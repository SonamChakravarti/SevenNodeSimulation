/* 
 * File:   main.cpp
 * Author: Sona
 *
 * Created on November 11, 2013, 9:56 PM
 */

#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;


class Help{
public:
    double random(){
      double random_once;
      random_once=(double)rand()/RAND_MAX;
    //  cout<<random_once;
      return random_once;
        
    }
};
int main()
{

    Help h;
    double ran;
    int calls;
    int opt;
    int through,loss;
    double b[7];
    double val;
    double step;
    double manual_loss;
    cout<<"Total number of calls"<<endl;
    cin>>calls;
    cout<<"Blocking probability options \n 1. All values same \n 2. Decrementing values"<<endl;
    cin>>opt;
    cout<<"Enter value"<<endl;
    cin>>val;
    if(opt==2)
    {
        cout<<"enter step"<<endl;
        cin>>step;
    }
    if(opt==1)
    {
        for(int i=0;i<7;i++)
        {
            b[i]=val;
        }
    }
    else
    {
        for(int i=0;i<7;i++){
            b[i]=val-(i*step);
        }
    }
    cout<<"Blocking Probability for links:"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<b[i]<<endl;
    }
    manual_loss=b[1]*b[4]*(1.0-((1.0-b[5])*(1.0-b[6])))*(1.0-b[0])*(1.0-b[2])*(1.0-b[3])+b[1]*(1.0-b[0])*(1.0-b[2])*b[3]+(1.0-b[0])*b[2]+b[0];
    cout<<manual_loss<<endl;
    through=0;
    loss=0;
    for(int i=0;i<calls;i++){
          ran=h.random();
    if(ran<b[0]) { // checks for A->D
        continue;        
    }//call lost at A
    else{  //reaches node D
        ran=h.random();
        if(ran<b[1]){  //checks for D->E
            ran=h.random();
            if(ran<b[3]){ //Checks for D->F
                continue; 
            }//call lost at D
            else{//reaches node F
                ran=h.random();
                if(ran<b[4]){ // checks for F->E
                      ran=h.random();
                    if(ran<b[5]){//checks for F->G
                        continue;
                    }//call lost at F
                    else{ // call reaches node G
                        ran=h.random();
                        if(ran<b[6]){
                            continue;
                        }//call lost at Node G
                        else { //call reaches node E
                            ran=h.random();
                            if(ran<b[2]){
                                continue;
                            }//call lost at node E
                            else{
                                through++;
                            }// call reaches C
                        }
                    }
                }//does not reach node E
                else{// reaches node E
                    ran=h.random();
                    if(ran<b[2]){
                        continue;
                    }//call lost at E
                    else
                    {
                        through++;
                    }//call reaches C
                }
                
            }
        }// if < b[1] 
        else{ //reaches node E
            ran=h.random();
            if(ran<b[2]){
                continue;
            }//call lost at E
            else{
                through++;
            }// call reaches C
        }
       
    }
    }
    cout<<through<<endl;
 
 return 0;
}