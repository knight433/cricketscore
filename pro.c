#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

char this_over[3][10];

struct Team1
{
    char name[10];
    int runs;
    int balls;
    int fours;
    int six;
    int if_bat;
}t1[12];

struct Team2
{
    char name[10];
    int runs;
    int balls;
    int fours;
    int six;
    int if_bat;
}t2[12];


int bowl(char res[3])
{
    if(strcmp(res,"1") == 0)
        return 1;
    
    else if (strcmp(res,"2") == 0)
        return 2;
    
    else if (strcmp(res,"3") == 0)
        return 3;
    
    else if (strcmp(res,"4") == 0)
        return 4;
    
    else if (strcmp(res,"5") == 0)
        return 5;
    
    else if (strcmp(res,"6") == 0)
        return 6;
    
    else if (strcmp(res,"1lb") == 0)
        return 7;
    
    else if (strcmp(res,"2lb") == 0)
        return 8;
    
    else if (strcmp(res,"3lb") == 0)
        return 9;
    
    else if (strcmp(res,"4lb") == 0)
        return 10;
    
    else if (strcmp(res,"wd") == 0)
        return 11;
    
    else if (strcmp(res,"1wd") == 0)
        return 12;
    
    else if (strcmp(res,"2wd") == 0)
        return 13;
    
    else if (strcmp(res,"3wd") == 0)
        return 14;
    
    else if (strcmp(res,"4wd") == 0)
         return 15;
    
    else if (strcmp(res,"w") == 0)
        return 16;
    
    else if (strcmp(res,"1w") == 0)
        return 17;
    else if (strcmp(res,"0") == 0)
        return 18;
    else if (strcmp(res,"nb") == 0)
        return 19;

}

int main()
{
    int i,bat,runs,j,overs,n1,n2,int_res,bowler,on_strike,off_strike,score=0,wickets=0,temp,k,balls_bowled=0;
    int run_rem,balls_rem,loop,acc_balls;
    float strike_rate1,strike_rate2;
    char team1[10],team2[10],current_bat[10],res[3];
    bool new = false;
    printf("enter the numeber of overs in an innings: ");
    scanf("%d",&overs);
    printf("enter the name of team 1: ");
    scanf("%s",team1);
    printf("enter the player name in %s\n",team1);
    for ( i = 1; i < 12; i++)
    {
        printf("player %d: ",i);
        scanf("%s",t1[i].name);
        t1[i].balls = 0;
        t1[i].fours = 0;
        t1[i].runs = 0;
        t1[i].six = 0;
        t1[i].if_bat = 0;
    }
    
    printf("\nEnter the name of team 2: ");
    scanf("%s",team2);
    printf("enter the player name in %s\n",team2);
    for ( i = 1; i < 12; i++)
    {
        printf("player %d: ",i);
        scanf("%s",t2[i].name);
        t2[i].balls = 0;
        t2[i].fours = 0;
        t2[i].runs = 0;
        t2[i].six = 0;
        t2[i].if_bat = 0;

    }
    
    printf("Which team is batting first: (1) or (2) ");
    scanf("%d",&bat);
    if(bat == 1)
        strcpy(current_bat,team1);
    else
        strcpy(current_bat,team2);
    printf("\nEnter the number of the first batsmen from %s: ",current_bat);
    scanf("%d",&n1);
    printf("\nEnter the number of the second batsmen from %s: ",current_bat);
    scanf("%d",&n2);
    on_strike = n1;
    off_strike = n2;
    if(bat == 1)
    {
        t1[on_strike].if_bat=1;
        t1[off_strike].if_bat=1;
        for ( i = 0; i < overs; i++)
        {
            printf("\nEnter the number of the bowler: ");
            scanf("%d",&bowler);
            balls_bowled = 0;

            for (j = 1; j < 7; j++)
            {
                loop = 0;
                printf("\n%s: %d/%d (%d.%d)",current_bat,score,wickets,i,j-1);
                printf("\n%s*: %d(%d) 4s: %d 6s: %d",t1[on_strike].name,t1[on_strike].runs ,t1[on_strike].balls, t1[on_strike].fours,t1[on_strike].six);
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t1[off_strike].name,t1[off_strike].runs,t1[off_strike].balls, t1[off_strike].fours,t1[off_strike].six);
                printf("\n%s bowling to %s: \n",t2[bowler].name,t1[on_strike].name);
                printf("%d.%d: ",i,j);
                scanf("%s",res);
                int_res = bowl(res);
                switch(int_res){

                    case 1: t1[on_strike].runs++;
                            t1[on_strike].balls++; 
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            break;
                    case 2: t1[on_strike].runs+=2;
                            t1[on_strike].balls++;
                            score+=2;
                            break;
                    case 3: t1[on_strike].runs+=3;
                            t1[on_strike].balls++;
                            score+=3;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            break;
                    case 4: t1[on_strike].balls++;
                            t1[on_strike].runs+=4;
                            t1[on_strike].fours++;
                            score+=4;
                            break;
                    case 5: t1[on_strike].balls++;
                            t1[on_strike].runs+=5;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=5;
                            break;
                    case 6: t1[on_strike].balls++;
                            t1[on_strike].runs+=6;
                            t1[on_strike].six++;
                            score+=6;
                            break;
                    case 7: t1[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            break;
                    case 8: t1[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=2;
                            break;
                    case 9: t1[on_strike].balls++;
                            score+=3;
                            break;
                    case 10: t1[on_strike].balls++;
                             score+=4;
                             break;
                    case 11: score++;
                             j--;
                             break;
                    case 12: score+=2;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 13: score+=3;
                             j--;
                             break;
                    case 14: score+=4;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 15: score+=5;
                             j--;
                             break;
                    case 16: t1[on_strike].balls++;
                             wickets++;
                             printf("\nEnter the next batsmen number : ");
                            do
                            {
                                scanf("%d",&on_strike);
                                if (t1[on_strike].if_bat==0)
                                {
                                    t1[on_strike].if_bat=1;
                                    loop = 1;
                                }
                                else 
                                {
                                    printf("\nThis batsman is already OUT enter a valid batsman: ");
                                }
                            }while(loop == 0); //while loop
                            new = true;
                             break;
                    case 18: t1[on_strike].balls++;
                             break;
                    case 19: score++;
                             j--;
                             break;

                    default: printf("***Not a vaild input***\n");
                             j--;
                             break;
                    
                } // switch
                strcpy(this_over[balls_bowled],res);
                balls_bowled++;
            }
            temp = on_strike;
            on_strike = off_strike;
            off_strike = temp;
            printf("\nThis over[");
            for (k=0;k<balls_bowled;k++)
            {
                printf("%s ",this_over[k]);
            }
            printf("]\n");
           
        }//overs1
        printf ("Team %s : scorcard",team1);
        for ( i = 1; i <= wickets+2; i++)
        {
            if(t1[i].if_bat = 1)
            {
                if( i == on_strike || i == off_strike)
                {
                    printf("\n%s*: %d(%d) 4s: %d 6s: %d",t1[i].name,t1[i].runs ,t1[i].balls, t1[i].fours,t1[i].six);
                }
                else
                { 
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t1[i].name,t1[i].runs ,t1[i].balls, t1[i].fours,t1[i].six);
                }
            } 
        }
        printf("\n\n");
        strcpy(current_bat,team2);
        run_rem = score+1;
        score = 0;
        wickets = 0;
        balls_rem = (overs*6);
        printf("\nTeam %s need %d in %d balls",team2,run_rem,balls_rem);
        printf("\nEnter the number of the first batsmen from %s: ",current_bat);
        scanf("%d",&n1);
        printf("\nEnter the number of the second batsmen from %s: ",current_bat);
        scanf("%d",&n2);
        on_strike = n1;
        off_strike = n2;
        for( i = 0; i < overs; i++)
        {
            printf("\nEnter the number of the bowler: ");
            scanf("%d",&bowler);
            balls_bowled = 0;

            for (j = 1; j < 7; j++)
            {
                loop = 0;
                
                printf("\n%s: %d/%d (%d.%d)",current_bat,score,wickets,i,j-1);
                printf("\n%s*: %d(%d) 4s: %d 6s: %d",t2[on_strike].name,t2[on_strike].runs ,t2[on_strike].balls, t2[on_strike].fours,t2[on_strike].six);
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t2[off_strike].name,t2[off_strike].runs,t2[off_strike].balls, t2[off_strike].fours,t2[off_strike].six);
                printf("\nTeam %s need %d in %d balls",team2,run_rem,balls_rem);
                printf("\n%s bowling to %s: ",t1[bowler].name,t2[on_strike].name);
                printf("\n%d.%d: ",i,j);
                scanf("%s",res);
                int_res = bowl(res);
                switch(int_res){

                    case 1: t2[on_strike].runs++;
                            t2[on_strike].balls++; 
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            run_rem--;
                            break;
                    case 2: t2[on_strike].runs+=2;
                            t2[on_strike].balls++;
                            score+=2;
                            run_rem-=2;
                            break;
                    case 3: t2[on_strike].runs+=3;
                            t2[on_strike].balls++;
                            score+=3;
                            run_rem-=3;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            break;
                    case 4: t2[on_strike].balls++;
                            t2[on_strike].runs+=4;
                            t2[on_strike].fours++;
                            score+=4;
                            run_rem-=4;
                            break;
                    case 5: t2[on_strike].balls++;
                            t2[on_strike].runs+=5;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=5;
                            run_rem-=5;
                            break;
                    case 6: t2[on_strike].balls++;
                            t2[on_strike].runs+=6;
                            t2[on_strike].six++;
                            score+=6;
                            run_rem-=6;
                            break;
                    case 7: t2[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            run_rem--;
                            break;
                    case 8: t2[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=2;
                            run_rem-=2;
                            break;
                    case 9: t2[on_strike].balls++;
                            score+=3;
                            run_rem-=3;
                            break;
                    case 10: t2[on_strike].balls++;
                             score+=4;
                             run_rem-=4;
                             break;
                    case 11: score++;
                             run_rem--;
                             j--;
                             break;
                    case 12: score+=2;
                             run_rem-=2;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 13: score+=3;
                             run_rem-=3;
                             j--;
                             break;
                    case 14: score+=4;
                             run_rem-=4;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 15: score+=5;
                             run_rem-=5;
                             j--;
                             break;
                    case 16: t2[on_strike].balls++;
                             wickets++;
                             printf("\nEnter the next batsmen number : ");
                            do
                            {
                                scanf("%d",&on_strike);
                                if (t2[on_strike].if_bat==0)
                                {
                                    t2[on_strike].if_bat=1;
                                    loop = 1;
                                }
                                else 
                                {
                                    printf("\nThis batsman is already OUT enter a valid batsman: ");
                                }
                            }while(loop == 0);//do while loop
                    case 18: t2[on_strike].balls++;
                             break;
                    case 19: score++;
                             j--;
                             break;

                    default: printf("***Not a vaild input***\n");
                             j--;
                             break;
                    
                } // switch
                strcpy(this_over[balls_bowled],res);
                balls_bowled++;
                balls_rem--;
                if(run_rem<=0){
                    printf("%s have won the match by %d wickets and %d balls remaining",team2,(10-wickets),balls_rem);
                    printf("\n\n");
                    printf ("Team %s : scorcard",team2);
                    for ( i = 1; i <= wickets+2; i++)
                    {
                        if(t2[i].if_bat = 1)
                        {
                            if( i == on_strike || i == off_strike)
                            {
                                printf("\n%s*: %d(%d) 4s: %d 6s: %d",t2[i].name,t2[i].runs ,t2[i].balls, t2[i].fours,t2[i].six);
                            }
                            else
                            { 
                            printf("\n%s: %d(%d) 4s: %d 6s: %d",t2[i].name,t2[i].runs ,t2[i].balls, t2[i].fours,t2[i].six);
                            }
                        } 
                    }
                    
                    exit(0);
                }
                
            }
            temp = on_strike;
            on_strike = off_strike;
            off_strike = temp;
            printf("\nThis over[");
            for (int k=0;k<balls_bowled;k++)
            {
                printf("%s ",this_over[k]);
            }
            printf("]\n");
           
        }//overs2
        if(run_rem == 1)
        {
            printf("\nThe result is a tie");
        }
        else
        {
            printf("%s have won the match by %d runs",team1,run_rem);
        }
        printf ("\n\nTeam %s : scorcard",team2);
        for ( i = 1; i <= wickets+2; i++)
        {
            if(t2[i].if_bat = 1)
            {
                if( i == on_strike || i == off_strike)
                {
                    printf("\n%s*: %d(%d) 4s: %d 6s: %d",t2[i].name,t2[i].runs ,t2[i].balls, t2[i].fours,t2[i].six);
                }
                else
                { 
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t2[i].name,t2[i].runs ,t2[i].balls, t2[i].fours,t2[i].six);
                }
            } 
        }
        printf("\n\n");

    } // if bat == 1
    else if(bat == 2)
    {
        for ( i = 0; i < overs; i++)
        {
            printf("\nEnter the number of the bowler: ");
            scanf("%d",&bowler);
            balls_bowled = 0;

            for (j = 1; j < 7; j++)
            {
                loop = 0;
                printf("\n%s: %d/%d (%d.%d)",current_bat,score,wickets,i,j-1);
                printf("\n%s*: %d(%d) 4s: %d 6s: %d",t2[on_strike].name,t2[on_strike].runs ,t2[on_strike].balls, t2[on_strike].fours,t2[on_strike].six);
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t2[off_strike].name,t2[off_strike].runs,t2[off_strike].balls, t2[off_strike].fours,t2[off_strike].six);
                printf("\n%s bowling to %s: ",t1[bowler].name,t2[on_strike].name);
                printf("\n%d.%d: ",i,j);
                scanf("%s",res);
                int_res = bowl(res);
                switch(int_res){

                    case 1: t2[on_strike].runs++;       
                            t2[on_strike].balls++; 
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            break;
                    case 2: t2[on_strike].runs+=2;
                            t2[on_strike].balls++;
                            score+=2;
                            break;
                    case 3: t2[on_strike].runs+=3;
                            t2[on_strike].balls++;
                            score+=3;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            break;
                    case 4: t2[on_strike].balls++;
                            t2[on_strike].runs+=4;
                            t2[on_strike].fours++;
                            score+=4;
                            break;
                    case 5: t2[on_strike].balls++;
                            t2[on_strike].runs+=5;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=5;
                            break;
                    case 6: t2[on_strike].balls++;
                            t2[on_strike].runs+=6;
                            t2[on_strike].six++;
                            score+=6;
                            break;
                    case 7: t2[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            break;
                    case 8: t2[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=2;
                            break;
                    case 9: t2[on_strike].balls++;
                            score+=3;
                            break;
                    case 10: t2[on_strike].balls++;
                             score+=4;
                             break;
                    case 11: score++;
                             j--;
                             break;
                    case 12: score+=2;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 13: score+=3;
                             j--;
                             break;
                    case 14: score+=4;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 15: score+=5;
                             j--;
                             break;
                    case 16: t2[on_strike].balls++;
                             wickets++;
                             printf("\nEnter the next batsmen number : ");
                             do
                            {
                                scanf("%d",&on_strike);
                                if (t2[on_strike].if_bat==0)
                                {
                                    t2[on_strike].if_bat=1;
                                    loop = 1;
                                }
                                else 
                                {
                                    printf("\nThis batsman is already OUT enter a valid batsman: ");
                                }
                            }while(loop == 0);//do while loop
                             break;
                    case 18: t2[on_strike].balls++;
                             break;
                    case 19: score++;
                             j--;
                             break;

                    default: printf("***Not a vaild input***\n");
                             j--;
                             break;
                    
                } // switch
                strcpy(this_over[balls_bowled],res);
                balls_bowled++;
                
            }
            temp = on_strike;
            on_strike = off_strike;
            off_strike = temp;
            printf("\nThis over[");
            for (int k=0;k<balls_bowled;k++)
            {
                printf("%s ",this_over[k]);
            }
            printf("]\n");
           
        }//overs1
        printf("\nTeam %s scorcard",team2);
        for ( i = 1; i <= wickets+2; i++)
            {
                if(t2[i].if_bat = 1)
                {
                    if( i == on_strike || i == off_strike)
                    {
                        printf("\n%s*: %d(%d) 4s: %d 6s: %d",t2[i].name,t2[i].runs ,t2[i].balls, t2[i].fours,t2[i].six);
                    }
                    else
                    { 
                    printf("\n%s: %d(%d) 4s: %d 6s: %d",t2[i].name,t2[i].runs ,t2[i].balls, t2[i].fours,t2[i].six);
                    }
                } 
            }
        printf("\n\n");
        strcpy(current_bat,team1);
        run_rem = score+1;
        score = 0;
        wickets = 0;
        balls_rem = (overs*6);
        printf("\nTeam %s need %d in %d balls",team1,run_rem,balls_rem);
        printf("\nEnter the number of the first batsmen from %s: ",current_bat);
        scanf("%d",&n1);
        printf("\nEnter the number of the second batsmen from %s: ",current_bat);
        scanf("%d",&n2);
        on_strike = n1;
        off_strike = n2;
        for( i = 0; i < overs; i++)
        {
            printf("\nEnter the number of the bowler: ");
            scanf("%d",&bowler);
            balls_bowled = 0;

            for (j = 1; j < 7; j++)
            {
                loop = 0;
                printf("\n%s: %d/%d (%d.%d)",current_bat,score,wickets,i,j-1);
                printf("\n%s*: %d(%d) 4s: %d 6s: %d",t1[on_strike].name,t1[on_strike].runs ,t1[on_strike].balls, t1[on_strike].fours,t1[on_strike].six);
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t1[off_strike].name,t1[off_strike].runs,t1[off_strike].balls, t1[off_strike].fours,t1[off_strike].six);
                printf("\nTeam %s need %d in %d balls",team1,run_rem,balls_rem);
                printf("\n%s bowling to %s: ",t2[bowler].name,t1[on_strike].name);
                printf("\n%d.%d: ",i,j-1);
                scanf("%s",res);
                int_res = bowl(res);
                switch(int_res){

                    case 1: t1[on_strike].runs++;
                            t1[on_strike].balls++; 
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            run_rem--;
                            break;
                    case 2: t1[on_strike].runs+=2;
                            t1[on_strike].balls++;
                            score+=2;
                            run_rem-=2;
                            break;
                    case 3: t1[on_strike].runs+=3;
                            t1[on_strike].balls++;
                            score+=3;
                            run_rem-=3;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            break;
                    case 4: t1[on_strike].balls++;
                            t1[on_strike].runs+=4;
                            t1[on_strike].fours++;
                            score+=4;
                            run_rem-=4;
                            break;
                    case 5: t1[on_strike].balls++;
                            t1[on_strike].runs+=5;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=5;
                            run_rem-=5;
                            break;
                    case 6: t1[on_strike].balls++;
                            t1[on_strike].runs+=6;
                            t1[on_strike].six++;
                            score+=6;
                            run_rem-=6;
                            break;
                    case 7: t1[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score++;
                            run_rem--;
                            break;
                    case 8: t1[on_strike].balls++;
                            temp = on_strike;
                            on_strike = off_strike;
                            off_strike = temp;
                            score+=2;
                            run_rem-=2;
                            break;
                    case 9: t1[on_strike].balls++;
                            score+=3;
                            run_rem-=3;
                            break;
                    case 10: t1[on_strike].balls++;
                             score+=4;
                             run_rem-=4;
                             break;
                    case 11: score++;
                             run_rem--;
                             j--;
                             break;
                    case 12: score+=2;
                             run_rem-=2;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 13: score+=3;
                             run_rem-=3;
                             j--;
                             break;
                    case 14: score+=4;
                             run_rem-=4;
                             j--;
                             temp = on_strike;
                             on_strike = off_strike;
                             off_strike = temp;
                             break;
                    case 15: score+=5;
                             run_rem-=5;
                             j--;
                             break;
                    case 16: t1[on_strike].balls++;
                             wickets++;
                             printf("\nEnter the next batsmen number : ");
                            do
                            {
                                scanf("%d",&on_strike);
                                if (t1[on_strike].if_bat==0)
                                {
                                    t1[on_strike].if_bat=1;
                                    loop = 1;
                                }
                                else 
                                {
                                    printf("\nThis batsman is already OUT enter a valid batsman: ");
                                }
                            }while(loop == 0);//do while loop
                    case 18: t1[on_strike].balls++;
                             break;
                    case 19: score++;
                             j--;
                             break;

                    default: printf("***Not a vaild input***\n");
                             j--;
                             break;
                    
                } // switch
                strcpy(this_over[balls_bowled],res);
                balls_bowled++;
                balls_rem--;
                if(run_rem<=0){
                    printf("%s have won the match by %d wickets and %d balls remaining",team1,(10-wickets),balls_rem);
                    printf("\n\n");
                    printf ("Team %s : scorcard",team1);
                    for ( i = 1; i <= wickets+2; i++)
                    {
                        if(t1[i].if_bat = 1)
                        {
                            if( i == on_strike || i == off_strike)
                            {
                                printf("\n%s*: %d(%d) 4s: %d 6s: %d",t1[i].name,t1[i].runs ,t1[i].balls, t1[i].fours,t1[i].six);
                            }
                            else
                            { 
                            printf("\n%s: %d(%d) 4s: %d 6s: %d",t1[i].name,t1[i].runs ,t1[i].balls, t1[i].fours,t1[i].six);
                            }
                        } 
                    }
                    exit(0);
                }
                
            }
            temp = on_strike;
            on_strike = off_strike;
            off_strike = temp;
            printf("\nThis over[");
            for (int k=0;k<balls_bowled;k++)
            {
                printf("%s ",this_over[k]);
            }
            printf("]\n");
           
        }//overs2
        
         if(run_rem == 1)
        {
            printf("\nThe result is a tie");
        }
        else
        {
            printf("%s have won the match by %d runs",team1,run_rem);
        }
        printf ("\n\nTeam %s : scorcard",team1);
        for ( i = 1; i <= wickets+2; i++)
        {
            if(t1[i].if_bat = 1)
            {
                if( i == on_strike || i == off_strike)
                {
                    printf("\n%s*: %d(%d) 4s: %d 6s: %d",t1[i].name,t1[i].runs ,t1[i].balls, t1[i].fours,t1[i].six);
                }
                else
                { 
                printf("\n%s: %d(%d) 4s: %d 6s: %d",t1[i].name,t1[i].runs ,t1[i].balls, t1[i].fours,t1[i].six);
                }
            } 
        }

    } // if bat == 2
    return 0;
    
} //main1
