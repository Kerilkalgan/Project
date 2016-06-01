#include <allegro.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int i=0,j=0;
 char num_1[3];//для хранения очков
 char num_2[3];
int line_x = 320,line_y = 30; //кооринаты средней линии
int ball_x = 320; //начальные координаты шарика
int ball_y = 240;

int ball_tempX = 320;
int ball_tempY = 240;

int p1_x = 20;//горизонтальная координата первой платформы
int p1_y = 210;//вертикальная координата

int p1_tempX = 20;
int p1_tempY = 210;

int p2_x = 620;//горизонтальная координата второй платформы
int p2_y = 210;//вертикальная координата

int p2_tempX = 620;
int p2_tempY = 210;

time_t secs;    //Секунды на системных часах 

int dir;     // Направление шарика
             // при dir = 1 - вверх и влево, = 2 -вниз и влево, = 3 -вверх и вправо, = 4-вниз и вправо
         
BITMAP *buffer; 


void moveBall()//движение шара
{
     
    ball_tempX = ball_x;
    ball_tempY = ball_y;

    if (dir == 1 && ball_x > 5 && ball_y > 5)//если шарик в пределах поля игры для направления 1
    {

         if( ball_x == p1_x + 15 && ball_y >= (p1_y-9) && ball_y <= p1_y + 100){//если шарик попадает в платформу 1
                  dir = rand()% 2 +3 ; // функция rand генерирует случайные числа, и шарик отбивается согласно путям 3 и 4
         }else{//продолжение перемещения в заданном направлении
                 --ball_x;
                 --ball_y;
         }

    } else if (dir == 2 && ball_x > 5 && ball_y < 475){//для направления 2

         if( ball_x == p1_x + 15 && ball_y >= (p1_y-9) && ball_y <= p1_y + 100){ //от p1_y и далее от p2_y вычитаем 9,добавлено для того, чтобы
                  dir = rand()% 2 + 3;                                           //при падении шарика сверху игрок смог его отбить(крайняя точка)
         }else{
                 --ball_x;
                 ++ball_y;
         }

    } else if (dir == 3 && ball_x < 640 && ball_y > 5){

         if( ball_x + 5 == p2_x && ball_y >= (p2_y-9) && ball_y <= p2_y + 100){
                  dir = rand()% 2 + 1;
         }else{
                 ++ball_x;
                 --ball_y;
         }

    } else if (dir == 4 && ball_x < 640 && ball_y < 475){

         if( ball_x + 5 == p2_x && ball_y >= (p2_y-9) && ball_y <= p2_y + 100){
                  dir = rand()% 2 + 1;
         }else{
                 ++ball_x;
                 ++ball_y;
         }

    } else {//движение шарика после столкновения с объектом (выбор дальнейшего пути)

        if (dir == 1 || dir == 3)    ++dir;
        else if (dir == 2 || dir == 4)    --dir;

    }

    acquire_screen();
    circlefill ( buffer, ball_tempX, ball_tempY, 5, makecol( 30, 0, 0)); 
    circlefill ( buffer, ball_x, ball_y, 5, makecol( 120, 55, 255)); // рисуем шарик с центром (ball_x,ball_y) и радиусом = 5, и указываем цвет шарика makecol (формат RGB)  
    draw_sprite( screen, buffer, 0, 0);
    release_screen();
    textout_ex( screen, font, "***PONG***", 283, 20, makecol( 0, 0, 0), makecol( 255, 255, 0));
    textout_ex( screen, font, num_1, 305, 65, makecol( 255, 255, 0), makecol( 0, 0, 0)); // вывод табло со счетом,очки первого
    textout_ex( screen, font, num_2, 333, 65, makecol( 255, 255, 0), makecol( 0, 0, 0)); // очки второго
    rectfill( buffer, line_x, line_y, line_x + 1, line_y + 480, makecol ( 240, 240, 240));// прорисовка средней линии
    rest(5);

}


void p1Move(){ // управление платформой  1

    p1_tempY = p1_y;

    if( key[KEY_W] && p1_y > 0){

        --p1_y;//платформа перемещается вверх на одну координату при нажатии

    } else if( key[KEY_S] && p1_y < 420){

        ++p1_y;

    }

    acquire_screen();
    rectfill( buffer, p1_tempX, p1_tempY, p1_tempX + 10, p1_tempY + 90, makecol ( 0, 0, 0));// при движении платформы, закрашивает черным его путь,для того чтобы видеть саму платформу
    rectfill( buffer, p1_x, p1_y, p1_x + 10, p1_y + 90, makecol ( 255, 255, 0)); //цвет первой платформы,и её размеры,координаты
    release_screen();

}

void p2Move(){ // управление платформой  2

    p2_tempY = p2_y;

    if( key[KEY_UP] && p2_y > 0){

        --p2_y;

    } else if( key[KEY_DOWN] && p2_y < 420){

        ++p2_y;

    }

    acquire_screen();
    rectfill( buffer, p2_tempX, p2_tempY, p2_tempX + 10, p2_tempY + 90, makecol ( 0, 0, 0));
    rectfill( buffer, p2_x, p2_y, p2_x + 10, p2_y + 90, makecol ( 10, 255, 0));
    release_screen();

}

void startNew()//начало новой игры
{
	 

    clear_keybuf();
    readkey();
    clear_to_color( buffer, makecol( 0, 0, 0)); // цвет экрана
    
    ball_x = 320;
    ball_y = 240;

    p1_x = 20;
    p1_y = 210;

    p2_x = 620;
    p2_y = 210;
   
}

void checkWin(){//Выявление победителя

 
    if ( ball_x < p1_x) 
    {     
        j++;        
        startNew();
        }
    if ( ball_x > p2_x)
    {      
        i++;
        startNew();
    }
sprintf(num_1,"%d",i); //считывание очков в num_1 из i
sprintf(num_2,"%d",j); //аналог. в num_2 из j

}

void setupGame(){ //начальная прорисовка экрана

    acquire_screen();
    rectfill( buffer, p1_x, p1_y, p1_x + 10, p1_y + 90, makecol ( 255, 255, 0));
    rectfill( buffer, p2_x, p2_y, p2_x + 10, p2_y + 90, makecol ( 0, 255, 0));
    rectfill( buffer, line_x, line_y, line_x + 1, line_y + 480, makecol ( 240, 240, 240));
    circlefill ( buffer, ball_x, ball_y, 5, makecol( 120, 55, 255));
   
    draw_sprite( screen, buffer, 0, 0);
    release_screen();
    textout_ex( screen, font, "***PONG***", 280, 20, makecol( 0, 0, 0), makecol( 255, 255, 0));//начальная прорисовка названия игры
    textout_ex( screen, font, "0", 305, 65, makecol( 255, 255, 0), makecol( 0, 0, 0)); // далее нулевого табло очков
    textout_ex( screen, font, "0", 333, 65, makecol( 255, 255, 0), makecol( 0, 0, 0));    
    time(&secs);
    srand( (unsigned int)secs);
    
    readkey(); //игра начнется только при нажатии клавиш  
    dir = rand() % 4 + 1; // здесь генирируется одно из четырех направлений движения в самом начале игры
}

int main(){

 
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);

    buffer = create_bitmap( 640, 480);

    setupGame();

    while( !key[KEY_ESC] && i<15 && j<15)   //Цикл игры, который можно прервать нажатив клавишу ESC 
		                                     //или при достижении одного из игроков 15 очков игра прекращается
    {   
	  while(key[KEY_P]);  // При нажатии клавиши P и удержании её игра будет остановлена
	  	
        p1Move();
        p2Move();
        moveBall();
        checkWin();
    }
    if (i>j)
    printf("Первый игрок выйграл со счетом %d : %d",i,j);
    if (i<j)
    printf("Второй игрок выйграл со счетом %d : %d",j,i);
    if (i==j)
    printf("Ничья со счетом %d : %d",i,j);
    return 0;
}
END_OF_MAIN();
