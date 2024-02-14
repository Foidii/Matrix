
#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

struct cell
{ 
    unsigned int x,y; 
    float val; 
};

class matrix
{
unsigned int size_x, size_y;


public:

vector<cell> maciez;

int get_x()
    {   
        return size_x;
    }


int get_y()
    {   
        return size_y;
    }

matrix(unsigned int xx, unsigned yy)
    {
        size_x = xx;
        size_y = yy;
    }

int mod_cell(unsigned int temp_x, unsigned int temp_y, float value)
    {
        int k = 0;
        if(temp_x>size_x || temp_y>size_y) 
        {
            cout<<"Poza zakresem\n";
            return 0;
        }
        for(int i = 0; i < maciez.size();i++)
        {
            if ((maciez[i].x == temp_x) && (maciez[i].y == temp_y)) 
            {
                maciez[i].val = value;
            }
            k++;
        }
        if(maciez[k].val != value)
        {
            cout<<"Nie ma takiej komorki\n";
            return 0;
        }
    }
int add_cell(unsigned int _x, unsigned int _y, float _val)
    {
        cell komorka;
        if(_x>size_x || _y>size_y) 
        {
            cout<<"Poza zakresem\n";
            return 0;
        }
        
        for(int i = 0; i < maciez.size();i++)
        {
            if(maciez[i].x == _x && maciez[i].y == _y )
            cout<<"komorka istnieje"<<endl; 
            return 0;
        }
        
        komorka.x = _x;
        komorka.y = _y;
        komorka.val = _val;
        maciez.push_back(komorka); 
        return 1;  
    }

int del_cell(unsigned int _x, unsigned int _y)
    {
        if(_x>size_x || _y>size_y) {cout<<"Poza zakresem\n";}
        for(int i = 0; i < maciez.size();i++)
        {
            if ((maciez[i].x == _x) && (maciez[i].y == _y))
            {
                maciez.erase(maciez.begin()+i);
                cout<<"usunieto\n";
            }
        }
        return 1;  
    }
    
    

/*matrix operator+(matrix dodawanie)
    {
        cell temp;
        if(dodawanie.get_x() > size_x || dodawanie.get_y() > size_y) {cout<<"niezgodne wielkosci macierzy"<<endl; exit(0);}
        
        matrix wynik(dodawanie.get_x(),dodawanie.get_y());

        for(int v = 0; v < maciez.size();v++)
            {
                for( int  o = 0; o < dodawanie.maciez.size(); o++ )
                if((maciez[v].x == dodawanie.maciez[o].x) && (maciez[v].y == dodawanie.maciez[o].y))
                {
                    temp.x = maciez[v].x;
                    temp.y = maciez[v].x;
                    temp.val = dodawanie.maciez[v].val + maciez[o].val;
                    wynik.maciez.push_back(temp);
                    
                }
                for( int  o = 0; o < dodawanie.maciez.size(); o++ )
                {
                    if((maciez[v].x == dodawanie.maciez[o].x) && (maciez[v].y != dodawanie.maciez[o].y))
                    temp.x = maciez[v].x;
                    temp.y = maciez[v].x;
                    temp.val = maciez[v].val;
                    wynik.maciez.push_back(temp);

                }
                for( int  o = 0; o < dodawanie.maciez.size(); o++ )
                {
                    if((maciez[v].x != dodawanie.maciez[o].x) && (maciez[v].y != dodawanie.maciez[o].y))
                    temp.x = maciez[v].x;
                    temp.y = maciez[v].x;
                    temp.val = maciez[v].val;
                    wynik.maciez.push_back(temp);

                }
                for( int  o = 0; o < dodawanie.maciez.size(); o++ )
                {
                    if((maciez[v].x == dodawanie.maciez[o].x) && (maciez[v].y != dodawanie.maciez[o].y))
                    temp.x = dodawanie.maciez[v].x;
                    temp.y = dodawanie.maciez[v].x;
                    temp.val = dodawanie.maciez[v].val;
                    wynik.maciez.push_back(temp);

                }
                for( int  o = 0; o < dodawanie.maciez.size(); o++ )
                {
                    if((maciez[v].x != dodawanie.maciez[o].x) && (maciez[v].y != dodawanie.maciez[o].y))
                    temp.x = maciez[v].x;
                    temp.y = maciez[v].x;
                    temp.val = maciez[v].val;
                    wynik.maciez.push_back(temp);

                }

            

                return wynik;

/*
matrix operator-(matrix dodawanie)
    {
        cell temp;
        if(dodawanie.get_x() > size_x || dodawanie.get_y() > size_y) {cout<<"niezgodne wielkosci macierzy"<<endl; exit(0);}
        
        matrix wynik(dodawanie.get_x(),dodawanie.get_y());

        for(int v = 0; v < maciez.size();v++)
            {
                for( int  o = 0; o < dodawanie.maciez.size(); o++ )
                if((maciez[v].x == dodawanie.maciez[o].x) && (maciez[v].y == dodawanie.maciez[o].y))
                {
                    temp.x = maciez[v].x;
                    temp.y = maciez[v].x;
                    temp.val = dodawanie.maciez[v].val - maciez[o].val;
                    wynik.maciez.push_back(temp);
                    
                }
                }
                return wynik;
    }
    */



};

ostream& operator<<(ostream& str, matrix maciez)
{
    for( int i = 0; i < maciez.get_x(); i++)
    {
        for(int j = 0; j< maciez.get_y(); j++)
        {
            for ( int p = 0; p < maciez.maciez.size(); p++)
            {
            if( (maciez.maciez[p].x == j) && (maciez.maciez[p].y == i) )
            {
                cout<<maciez.maciez[p].val<<" ";
            }
            else cout <<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return str;
}




int main()
{
    matrix mat(30,30);
    matrix mat2(10,10);
    mat.add_cell(1,1,3);
    mat2.add_cell(1,2,2);

    cout<<mat;
    cout<<mat2; 
}