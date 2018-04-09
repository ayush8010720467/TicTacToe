#include<stdio.h>
int check(char ch[3][3]);
void print(char ch[3][3]);
char* position(char [3][3],char);
int valid(char);
main()
{
    char ch[3][3],ch1='1',*pos,point;
    int i=0,j=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    {
        ch[i][j]=ch1;
        ch1++;

    }
    printf("for player 1 X and for player 2 O \n");
    print(ch);
    for(i=0;i<9;i++)
    {
        if(i%2==0)
        {
            lable1:printf("Player 1 enter choice from 1 to 9\n");
            scanf(" %c",&point);
            if(!valid(point))
            {
                printf("\nenter the choice from 1 to 9\n");
                goto lable1;
            }
            else
            {
                pos=position(ch,point);
                *pos='X';
                print(ch);
                if(check(ch))
                {
                    printf("player 1 wins");
                    exit(0);
                }
            }
        }
        else
        {
            lable2:printf("Player 2 enter choice from 1 to 9\n");
            scanf(" %c",&point);
            if(!valid(point))
            {
                printf("\nenter the choice from 1 to 9\n");
                goto lable2;
            }
            else
            {
                pos=position(ch,point);
                *pos='O';
                print(ch);
                if(check(ch))
                {
                    printf("player 2 wins");
                    exit(0);
                }
        }
    }
}
}
int check(char ch[3][3])
{
    if((ch[0][0]==ch[0][1]&&ch[0][1]==ch[0][2])||(ch[1][0]==ch[1][1]&&ch[1][1]==ch[1][2])||(ch[2][0]==ch[2][1]&&ch[2][1]==ch[2][2]))
        return 1;
    else
    {
         if((ch[0][0]==ch[1][0]&&ch[1][0]==ch[2][0])||(ch[0][1]==ch[1][1]&&ch[1][1]==ch[2][1])||(ch[0][2]==ch[1][2]&&ch[1][2]==ch[2][2]))
        return 1;
        else
        {
            if((ch[0][0]==ch[1][1]&&ch[1][1]==ch[2][2])||(ch[0][2]==ch[1][1]&&ch[1][1]==ch[2][0]))
                return 1;
            else
                return 0;
        }
    }
}
char* position(char ch[3][3],char a)
{
    char* pos;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a==ch[i][j])
                pos=&ch[i][j];
        }
    }
    return pos;
}
int valid(char ch)
{
    int val=ch;
    if(val>48&&val<=57)
        return 1;
    return 0;
}
void print(char ch[3][3])
{
    printf("\n");
    int i,j;
    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
        printf("%c  ",ch[i][j]);
     printf("\n\n");

}
}
