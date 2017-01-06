#include<iostream>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<memory.h>
#include<vector>
#include<ctime>
#include<unistd.h>

using namespace std;

class Grids{
public:
    double r=1.0,g=1.0,b=1.0;
};

int noRow = 12,noCol =15;

Grids grid_color[12][15];

double width=1000,height=600;

double grid_width = 50;
bool grid = true;

int curr_tetrimino;

double transX=0.0,transY=0.0;

int orientation;

int p=4,q=0;

vector<pair<double,double> > tetriminos[6];

double heights[15];

void writeBitmapString(void *font, char *string){
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void tetrimino(){
    tetriminos[0].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[0].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[0].push_back(make_pair(8*grid_width,height-grid_width));
    tetriminos[0].push_back(make_pair(9*grid_width,height-grid_width));

    tetriminos[0].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[0].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[0].push_back(make_pair(7*grid_width,height-3*grid_width));
    tetriminos[0].push_back(make_pair(7*grid_width,height-4*grid_width));


    tetriminos[1].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[1].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[1].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[1].push_back(make_pair(7*grid_width,height-2*grid_width));


    tetriminos[2].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[2].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[2].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[2].push_back(make_pair(8*grid_width,height-2*grid_width));

    tetriminos[2].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[2].push_back(make_pair(6*grid_width,height-3*grid_width));
    tetriminos[2].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[2].push_back(make_pair(7*grid_width,height-2*grid_width));


    tetriminos[3].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[3].push_back(make_pair(8*grid_width,height-grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-2*grid_width));

    tetriminos[3].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-3*grid_width));

    tetriminos[3].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[3].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[3].push_back(make_pair(8*grid_width,height-2*grid_width));

    tetriminos[3].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[3].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[3].push_back(make_pair(6*grid_width,height-3*grid_width));
    tetriminos[3].push_back(make_pair(7*grid_width,height-2*grid_width));


    tetriminos[4].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[4].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[4].push_back(make_pair(8*grid_width,height-grid_width));
    tetriminos[4].push_back(make_pair(8*grid_width,height-2*grid_width));

    tetriminos[4].push_back(make_pair(6*grid_width,height-3*grid_width));
    tetriminos[4].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[4].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[4].push_back(make_pair(7*grid_width,height-3*grid_width));

    tetriminos[4].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[4].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[4].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[4].push_back(make_pair(8*grid_width,height-2*grid_width));

    tetriminos[4].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[4].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[4].push_back(make_pair(6*grid_width,height-3*grid_width));
    tetriminos[4].push_back(make_pair(7*grid_width,height-grid_width));


    tetriminos[5].push_back(make_pair(7*grid_width,height-grid_width));
    tetriminos[5].push_back(make_pair(8*grid_width,height-grid_width));
    tetriminos[5].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[5].push_back(make_pair(7*grid_width,height-2*grid_width));

    tetriminos[5].push_back(make_pair(6*grid_width,height-grid_width));
    tetriminos[5].push_back(make_pair(6*grid_width,height-2*grid_width));
    tetriminos[5].push_back(make_pair(7*grid_width,height-2*grid_width));
    tetriminos[5].push_back(make_pair(7*grid_width,height-3*grid_width));
}

void draw_line(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(3.0/4*width,0.0,0.0);
        glVertex3f(3.0/4*width,height,0.0);
        glVertex3f(3.0/4*width+20,height,0.0);
        glVertex3f(3.0/4*width+20,0.0,0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(0.0,height,0.0);
        glVertex3f(0.0,height+20,0.0);
        glVertex3f(3.0/4*width+20,height+20,0.0);
        glVertex3f(3.0/4*width+20,height,0.0);
    glEnd();


   glColor3f(0.0,1.0, 0.0);
   glRasterPos3f(3.0/4*width+100,height, 0.0);
   writeBitmapString(GLUT_BITMAP_9_BY_15, "Score");

}

void draw_grid(){
    glColor3f(0.0,0.0,0.0);
    double t=0;

    while(t<=3.0/4*width){
        glBegin(GL_LINES);
            glVertex3f(t,0.0,0.0);
            glVertex3f(t,height,0.0);
        glEnd();
        t+=grid_width;
    }

    t=0;
    while(t<=height){
        glBegin(GL_LINES);
            glVertex3f(0.0,t,0.0);
            glVertex3f(3.0/4*width,t,0.0);
        glEnd();
        t+=grid_width;
    }

}

void update_heights(){
    int i,j;

    for(i=noRow-1;i>=0;i--){
        for(j=0;j<noCol;j++){
            cout<<grid_color[i][j].r<<grid_color[i][j].g<<grid_color[i][j].b<<" ";
        }

        cout<<endl;
    }


    for(i=0;i<noCol;i++){
        for(j=0;j<noRow;j++){
            //cout<<grid_color[j][i].r<<" "<<grid_color[j][i].g<<" "<<grid_color[j][i].b<<endl;
            if(grid_color[j][i].r==1.0&&grid_color[j][i].g==1.0&&grid_color[j][i].b==1.0){
                break;
            }
        }
        heights[i]=grid_width*j;
        //cout<<i<<" "<<j<<endl;
    }

}

bool color = true;
bool fall = false;
bool wait_for_next;

int wait_counter;

double r=0.0,g=0.0,b=0.0;

void paint_grids(){
    int min_diff = 1000000,ind=0,ht=0;
    for(int i=0;i<4;i++){
        if(tetriminos[p][i+q].second-heights[int((tetriminos[p][i+q].first+transX)/grid_width)]<min_diff){
            ind = i;
            min_diff = tetriminos[p][i+q].second-heights[int((tetriminos[p][i+q].first+transX)/grid_width)];
            ht = heights[int((tetriminos[p][i+q].first+transX)/grid_width)];
        }
    }
    //cout<<ht<<endl;
    if(p==0){
        if(q==0){
            ht/=grid_width;
            int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
            cout<<hor<<" "<<ht<<endl;
            int t=0;
            for(int i=ind;i>=0;i--){
                grid_color[ht][hor-t].r=r;
                grid_color[ht][hor-t].g=g;
                grid_color[ht][hor-t].b=b;
                t++;
            }
            t=1;
            for(int i=ind+1;i<4;i++){
                grid_color[ht][hor+t].r=r;
                grid_color[ht][hor+t].g=g;
                grid_color[ht][hor+t].b=b;
                t++;
            }
        }
        else{
            ht/=grid_width;
            int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
            cout<<hor<<" "<<ht<<endl;
            for(int i=0;i<4;i++){
                grid_color[ht+i][hor].r=r;
                grid_color[ht+i][hor].g=g;
                grid_color[ht+i][hor].b=b;
            }
        }
    }

    else if(p==1){
        ht/=grid_width;
        int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
        if(ind==2){
            grid_color[ht][hor].r=r;
            grid_color[ht][hor].g=g;
            grid_color[ht][hor].b=b;
            grid_color[ht+1][hor].r=r;
            grid_color[ht+1][hor].g=g;
            grid_color[ht+1][hor].b=b;
            grid_color[ht][hor+1].r=r;
            grid_color[ht][hor+1].g=g;
            grid_color[ht][hor+1].b=b;
            grid_color[ht+1][hor+1].r=r;
            grid_color[ht+1][hor+1].g=g;
            grid_color[ht+1][hor+1].b=b;
        }
        else{
            grid_color[ht][hor].r=r;
            grid_color[ht][hor].g=g;
            grid_color[ht][hor].b=b;
            grid_color[ht][hor-1].r=r;
            grid_color[ht][hor-1].g=g;
            grid_color[ht][hor-1].b=b;
            grid_color[ht+1][hor-1].r=r;
            grid_color[ht+1][hor-1].g=g;
            grid_color[ht+1][hor-1].b=b;
            grid_color[ht+1][hor].r=r;
            grid_color[ht+1][hor].g=g;
            grid_color[ht+1][hor].b=b;
        }
    }

    else if(p==2){
        ht/=grid_width;
        int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
        if(q==0){
            if(ind==0){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht-1][hor+1].r=r;
                grid_color[ht-1][hor+1].g=g;
                grid_color[ht-1][hor+1].b=b;
                grid_color[ht-1][hor+2].r=r;
                grid_color[ht-1][hor+2].g=g;
                grid_color[ht-1][hor+2].b=b;
            }
            else if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
                grid_color[ht+1][hor-2].r=r;
                grid_color[ht+1][hor-2].g=g;
                grid_color[ht+1][hor-2].b=b;
            }
        }

        else{
            if(ind==1){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
                grid_color[ht+2][hor+1].r=r;
                grid_color[ht+2][hor+1].g=g;
                grid_color[ht+2][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht-1][hor-1].r=r;
                grid_color[ht-1][hor-1].g=g;
                grid_color[ht-1][hor-1].b=b;
            }
        }
    }

    else if(p==5){
        ht/=grid_width;
        int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
        if(q==0){
            if(ind==1){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht-1][hor-1].r=r;
                grid_color[ht-1][hor-1].g=g;
                grid_color[ht-1][hor-1].b=b;
                grid_color[ht-1][hor-2].r=r;
                grid_color[ht-1][hor-2].g=g;
                grid_color[ht-1][hor-2].b=b;
            }
            else if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
                grid_color[ht+1][hor+2].r=r;
                grid_color[ht+1][hor+2].g=g;
                grid_color[ht+1][hor+2].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
            }
        }

        else{
            if(ind==1){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht-1][hor+1].r=r;
                grid_color[ht-1][hor+1].g=g;
                grid_color[ht-1][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
                grid_color[ht+2][hor-1].r=r;
                grid_color[ht+2][hor-1].g=g;
                grid_color[ht+2][hor-1].b=b;
            }
        }
    }

    else if(p==3){
        cout<<q<<" "<<ind<<endl;
        ht/=grid_width;
        int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
        if(q==0){
            if(ind==0){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht-1][hor+1].r=r;
                grid_color[ht-1][hor+1].g=g;
                grid_color[ht-1][hor+1].b=b;
                grid_color[ht][hor+2].r=r;
                grid_color[ht][hor+2].g=g;
                grid_color[ht][hor+2].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
            }
            else if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht][hor-2].r=r;
                grid_color[ht][hor-2].g=g;
                grid_color[ht][hor-2].b=b;
                grid_color[ht-1][hor+1].r=r;
                grid_color[ht-1][hor+1].g=g;
                grid_color[ht-1][hor+1].b=b;
            }
        }

        else if(q==4){

            if(ind==0){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht-1][hor+1].r=r;
                grid_color[ht-1][hor+1].g=g;
                grid_color[ht-1][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+2][hor].r=r;
                grid_color[ht+2][hor].g=g;
                grid_color[ht+2][hor].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
            }
        }

        if(q==8){
            if(ind==1){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
                grid_color[ht][hor+2].r=r;
                grid_color[ht][hor+2].g=g;
                grid_color[ht][hor+2].b=b;
            }
            else if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht][hor-2].r=r;
                grid_color[ht][hor-2].g=g;
                grid_color[ht][hor-2].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
            }
        }

        if(q==12){
            if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+2][hor].r=r;
                grid_color[ht+2][hor].g=g;
                grid_color[ht+2][hor].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
                grid_color[ht-1][hor-1].r=r;
                grid_color[ht-1][hor-1].g=g;
                grid_color[ht-1][hor-1].b=b;
            }
        }

    }


    else if(p==4){
        cout<<q<<" "<<ind<<endl;
        ht/=grid_width;
        int hor = (tetriminos[p][ind+q].first+transX)/grid_width;
        if(q==0){
            if(ind==0){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht][hor+2].r=r;
                grid_color[ht][hor+2].g=g;
                grid_color[ht][hor+2].b=b;
                grid_color[ht-1][hor+2].r=r;
                grid_color[ht-1][hor+2].g=g;
                grid_color[ht-1][hor+2].b=b;
            }
            else if(ind==1){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht-1][hor+1].r=r;
                grid_color[ht-1][hor+1].g=g;
                grid_color[ht-1][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
                grid_color[ht+1][hor-2].r=r;
                grid_color[ht+1][hor-2].g=g;
                grid_color[ht+1][hor-2].b=b;
            }
        }

        else if(q==4){

            if(ind==0){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht+1][hor+1].r=r;
                grid_color[ht+1][hor+1].g=g;
                grid_color[ht+1][hor+1].b=b;
                grid_color[ht+2][hor+1].r=r;
                grid_color[ht+2][hor+1].g=g;
                grid_color[ht+2][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht-1][hor].r=r;
                grid_color[ht-1][hor].g=g;
                grid_color[ht-1][hor].b=b;
                grid_color[ht-2][hor].r=r;
                grid_color[ht-2][hor].g=g;
                grid_color[ht-2][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
            }
        }

        if(q==8){
            if(ind==1){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht][hor+2].r=r;
                grid_color[ht][hor+2].g=g;
                grid_color[ht][hor+2].b=b;
            }
            else if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht][hor+1].r=r;
                grid_color[ht][hor+1].g=g;
                grid_color[ht][hor+1].b=b;
                grid_color[ht+1][hor-1].r=r;
                grid_color[ht+1][hor-1].g=g;
                grid_color[ht+1][hor-1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht][hor-2].r=r;
                grid_color[ht][hor-2].g=g;
                grid_color[ht][hor-2].b=b;
                grid_color[ht+1][hor-2].r=r;
                grid_color[ht+1][hor-2].g=g;
                grid_color[ht+1][hor-2].b=b;
            }
        }

        if(q==12){
            if(ind==2){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht+1][hor].r=r;
                grid_color[ht+1][hor].g=g;
                grid_color[ht+1][hor].b=b;
                grid_color[ht+2][hor].r=r;
                grid_color[ht+2][hor].g=g;
                grid_color[ht+2][hor].b=b;
                grid_color[ht+2][hor+1].r=r;
                grid_color[ht+2][hor+1].g=g;
                grid_color[ht+2][hor+1].b=b;
            }
            else if(ind==3){
                grid_color[ht][hor].r=r;
                grid_color[ht][hor].g=g;
                grid_color[ht][hor].b=b;
                grid_color[ht][hor-1].r=r;
                grid_color[ht][hor-1].g=g;
                grid_color[ht][hor-1].b=b;
                grid_color[ht-1][hor-1].r=r;
                grid_color[ht-1][hor-1].g=g;
                grid_color[ht-1][hor-1].b=b;
                grid_color[ht-2][hor-1].r=r;
                grid_color[ht-2][hor-1].g=g;
                grid_color[ht-2][hor-1].b=b;
            }
        }

    }

}

void destroy(){
    int i,j,k;
    for(i=noRow-1;i>=0;i--){
        int noFilled=0;
        for(j=0;j<noCol;j++){
            if(grid_color[i][j].r!=1.0&&grid_color[i][j].g!=1.0&&grid_color[i][j].b!=1.0){
                noFilled++;
            }
        }
        if(noFilled==noCol){
            for(k=i;k<noRow-1;k++){
                for(j=0;j<noCol;j++){
                    grid_color[k][j].r=grid_color[k+1][j].r;
                    grid_color[k][j].g=grid_color[k+1][j].g;
                    grid_color[k][j].b=grid_color[k+1][j].b;
                }
            }
        }
    }
}

void next_tetrimino(){

    if(fall){

        paint_grids();
        update_heights();
        destroy();

        fall=false;
        wait_for_next=true;
    }
    else if(wait_for_next){
        wait_counter++;
        if(wait_counter==2000){
            color=true;
            wait_for_next=false;
            wait_counter=0;
            transX=0;
            transY=0;
        }
    }
    else{
        if(color){
            srand(time(0));
            r=0,b=0,g=0;
            while(r+b+g==0||r+b+g==3){
                r=rand()%2;
                g=rand()%2;
                b=rand()%2;
            }
            //cout<<r<<" "<<g<<" "<<b<<endl;
            color=false;
            p=rand()%6;
        }

        glColor3f(r,g,b);

        if(p==0||p==2||p==5){
            if(orientation%2){
                q=4;
            }
            else{
                q=0;
            }
        }
        else if(p==3||p==4){
            if(orientation%4==0){
                q=0;
            }
            if(orientation%4==1){
                q=4;
            }
            if(orientation%4==2){
                q=8;
            }
            if(orientation%4==3){
                q=12;
            }
        }

        glPushMatrix();
            glTranslatef(transX,transY,0.0);
            for(int i=0;i<4;i++){
                glBegin(GL_POLYGON);
                    glVertex3f(tetriminos[p][i+q].first+1,tetriminos[p][i+q].second+1,0.0);
                    glVertex3f(tetriminos[p][i+q].first+1,tetriminos[p][i+q].second+grid_width-1,0.0);
                    glVertex3f(tetriminos[p][i+q].first+grid_width-1,tetriminos[p][i+q].second+grid_width-1,0.0);
                    glVertex3f(tetriminos[p][i+q].first+grid_width-1,tetriminos[p][i+q].second+1,0.0);
                glEnd();
            }

        glPopMatrix();
    }
}

void draw_config(){
    int t=grid_width;
    for(int i=0;i<noCol;i++){
        for(int j=0;j<noRow;j++){
            glColor3f(grid_color[j][i].r,grid_color[j][i].g,grid_color[j][i].b);
            glBegin(GL_POLYGON);
                glVertex3f(i*t+1,j*t+1,0.0);
                glVertex3f(i*t+1,j*t+t-1,0.0);
                glVertex3f(i*t+t-1,j*t+t-1,0.0);
                glVertex3f(i*t+t-1,j*t+1,0.0);
            glEnd();
        }
    }
}

int timer=0;

void idle(){
    timer++;
    if(timer==1500){
        transY -= 50;
        timer=0;
    }

    //update_heights();

	glutPostRedisplay();

}


void mouse(int button,int state,int x,int y){

}

void keyboardFunc(unsigned char key, int x, int y ){
	if(key == 27){
		exit(0);
	}
	if(key == 'g'){
        grid=!grid;
	}

}

void specialKeyInput(int key, int x, int y){
	if(key == GLUT_KEY_LEFT){
        transX -= 50;
        bool out = false;
        for(int i=0;i<4;i++){
            if(tetriminos[p][i+q].first+transX<0){
                out=true;
                break;
            }
        }
        if(out){
            transX += 50;
        }
	}
	else if(key == GLUT_KEY_RIGHT){
        transX += 50;
        bool out = false;
        for(int i=0;i<4;i++){
            if(tetriminos[p][i+q].first+transX>3.0*width/4-20){
                out=true;
                break;
            }
        }
        if(out){
            transX -= 50;
        }
    }
	else if(key == GLUT_KEY_UP){
        orientation += 1 ;
    }
	else if(key == GLUT_KEY_DOWN){
        fall = true;
    }
    glutPostRedisplay();
}

void myinit(){
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    draw_line();
    if(grid)
        draw_grid();
    draw_config();
    next_tetrimino();
	glFlush();
}


int main(int argc,char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width,height);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Tetris");

    tetrimino();

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutSpecialFunc(specialKeyInput);
	glutMouseFunc(mouse);
	myinit();

	glutMainLoop();

	return 0;
}
