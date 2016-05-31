#include <allegro.h>
#include <time.h>
#include <stdio.h>


int i=0,j=0;
 
int ball_x = 320; //начальные координаты шарика
int ball_y = 240;

int ball_tempX = 320;
int ball_tempY = 240;

int p1_x = 20;//горизонтальная координата первой платформы
int p1_y = 210;

int p1_tempX = 20;
int p1_tempY = 210;

int p2_x = 620;//горизонтальная координата второй платформы
int p2_y = 210;

int p2_tempX = 620;
int p2_tempY = 210;

time_t secs;    //Секунды на системных часах будут храниться здесь это будет использоваться в качестве затравки для srand ()

int dir;     // Направление шарика
             // при dir = 1 - вверх и влево, = 2 -вниз и влево, = 3 -вверх и вправо, = 4-вниз и вправо
         
BITMAP *buffer; //Это будет наша временная битовая карта для двойной буферизации


void moveBall()//движение шара
{
     
    ball_tempX = ball_x;
    ball_tempY = ball_y;

    if (dir == 1 && ball_x > 5 && ball_y > 5)//если шарик в пределах поля игры для направления 1
    {

         if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 100){//если шарик попадает в платформу 1
                  dir = rand()% 2 +3 ; // функция rand генерирует случайные числа, и шарик отбивается согласно путям 3 и 4
         }else{//продолжение перемещения в заданном направлении
                 --ball_x;
                 --ball_y;
         }

    } else if (dir == 2 && ball_x > 5 && ball_y < 475){//для направления 2

         if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 100){
                  dir = rand()% 2 + 3;
         }else{
                 --ball_x;
                 ++ball_y;
         }

    } else if (dir == 3 && ball_x < 640 && ball_y > 5){

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 100){
                  dir = rand()% 2 + 1;
         }else{
                 ++ball_x;
                 --ball_y;
         }

    } else if (dir == 4 && ball_x < 640 && ball_y < 475){

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 100){
                  dir = rand()% 2 + 1;
         }else{
                 ++ball_x;
                 ++ball_y;
         }

    } else {//движение шарика после столкновения с объектом

        if (dir == 1 || dir == 3)    ++dir;
        else if (dir == 2 || dir == 4)    --dir;

    }

    acquire_screen();
    circlefill ( buffer, ball_tempX, ball_tempY, 5, makecol( 100, 0, 0)); 
    circlefill ( buffer, ball_x, ball_y, 5, makecol( 128, 255, 0)); // рисуем шарик с центром и радиус, цвет шарика  
    draw_sprite( screen, buffer, 0, 0);
    release_screen();
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
    rectfill( buffer, p1_tempX, p1_tempY, p1_tempX + 10, p1_tempY + 90, makecol ( 0, 0, 0));
    rectfill( buffer, p1_x, p1_y, p1_x + 10, p1_y + 90, makecol ( 255, 255, 0)); //цвет первого, размеры
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
    rectfill( buffer, p2_x, p2_y, p2_x + 10, p2_y + 90, makecol ( 0, 255, 0));

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
        textout_ex( screen, font, "Player 2 Wins!", 240, 100, makecol( 255, 0, 0), makecol( 0, 0, 0));    
        j++;        
        startNew();
        }
    if ( ball_x > p2_x)
    {
        textout_ex( screen, font, "Player 1 Wins!", 240, 100, makecol( 255, 0, 0), makecol( 0, 0, 0));     
        i++;
        startNew();
    }
}

void setupGame(){//начальная прорисовка экрана

    acquire_screen();
    rectfill( buffer, p1_x, p1_y, p1_x + 10, p1_y + 90, makecol ( 255, 255, 0));
    rectfill( buffer, p2_x, p2_y, p2_x + 10, p2_y + 90, makecol ( 0, 255, 0));
    circlefill ( buffer, ball_x, ball_y, 5, makecol( 128, 255, 0));
   
    draw_sprite( screen, buffer, 0, 0);
    release_screen();

    time(&secs);
    srand( (unsigned int)secs);
    dir = rand() % 4 + 1;

}

int main(){

 
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);

    buffer = create_bitmap( 640, 480);

    setupGame();

    while( !key[KEY_ESC] && i<15 && j<15) {  //ESC для выхода из игры
		  
       
		   while(key[KEY_P]); // при удерживании клавиши P будет происходить пауза
			

        p1Move();
        p2Move();
        moveBall();
        checkWin();

    }
printf("Финальный счет %d : %d",i,j);
    return 0;

}
END_OF_MAIN();
