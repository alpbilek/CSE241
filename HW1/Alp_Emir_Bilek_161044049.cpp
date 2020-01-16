/*#HW1
 * ALP EMİR BİLEK
 * 161044049
*/
#include <iostream>
using namespace std;
//DEFINING THE BASIC FUNCTIONS.
void swap(int a[],int b[],int size);
void print(int a[],int size);
int main() {
    //GETTING AN HEIGHT FROM THE USER.
    int h;
    cout<<"give me a height:";
    cin>>h;
    int z,l,k;
    //SOME CALCULATIONS FOR THE HEART.
    l=(h+1)/2+1;
    //SOME PROCESSES FOR THE FİRST TWO LETTERS.
    int temp=1,heart;
    int tempa[h+1];
    int array[h+1];
    tempa[0]=1;
    tempa[1]=1;
    int multiplier=2,counter2=2;
    int divider=1,counter1=2;
    int temp3[3]={2,1,2};
    if(h==2){
        heart=1;
        cout<<temp<<endl;
        print(tempa,2);
        print(temp3,3);
        cout<<"Biggest number: "<<temp3[0]<<endl;
        cout<<"Heart of the pyramid: "<<heart<<" "<<heart;
    }
    else if(h==1){
        heart=1;
        cout<<temp<<endl;
        print(tempa,2);
        cout<<"Biggest number: "<<tempa[0]<<endl;
        cout<<"Heart of the pyramid: "<<heart<<" "<<heart;
    }
    //INPUT CHECKING.
    else if(h==0){
        cout<<"Unfortunately there is no triangle for the 0!!";
    }
    else if(h<0){
        cout<<"Unfortunately there is no triangle for the negative numbers!!";
    }
    else if(h>=44){
        cout<<"Unfortunately the number which is you entered is over the integer limit!!";
    }
    else{
        cout<<temp<<endl;
        print(tempa,2);
        for(int i=3;i<h+2;i++){
            array[0]=temp+tempa[0];
            array[1]=tempa[0];
            //FOR THE ODD LETTERS!
            if(i%2==1){
        //FILLING THE ARRAY'S HALF!
                for(int j=2;j<=(i/2);j++){
                    array[j]=tempa[j-1]*multiplier/divider;
                    if(counter1<3){
                        multiplier++;
                        divider++;
                        counter1++;
                    }
                    else if(counter1==3){
                        multiplier=multiplier+2;
                        divider++;
                        counter1++;
                    }
                    else if(counter1>=4){
                        multiplier=multiplier+3;
                        divider=divider+2;
                        counter1++;
                    }
                }
                multiplier=2;
                divider=1;
                counter1=2;
                z=(i/2)-1;
                //FILLING THE ARRAY'S OTHER HALF!
                for(int t=(i/2)+1;t<i;t++){
                    array[t]=array[z];
                    z--;
                }
                //PRINTING AND SWAPING THE TEMP AND MAIN ARRAYS
                print(array,i);
                temp=tempa[0];
                swap(tempa,array,h+1);
            }
            //FOR THE EVEN LETTERS
            else if(i%2==0){
                //FILLING THE HALF OF THE ARRAY!
                for(int m=2;m<i/2;m++){
                    array[m]=tempa[m-1]*multiplier/divider;
                    if(counter2<3){
                        multiplier++;
                        divider++;
                        counter2++;
                    }
                    else if(counter2==3){
                        multiplier=multiplier+2;
                        divider++;
                        counter2++;
                    }
                    else if(counter2>=4){
                        multiplier=multiplier+3;
                        divider=divider+2;
                        counter2++;
                    }
                }
                multiplier=2;
                divider=1;
                counter2=2;
                k=(i/2)-1;
                //FILLING THE OTHER HALF OF ARRAY!
                for(int n=i/2;n<i;n++){
                    array[n]=array[k];
                    k--;
                }
                //PRINTING AND SWAPING THE TEMP AND MAIN ARRAYS
                print(array,i);
                temp=tempa[0];
                swap(tempa,array,h+1);
            }
            //FINDING THE HEART OF THE PYRAMID.
            if(i==l){
                heart=array[i/2];
            }
        }
        //PRINTINF THE BIGGEST NUM!
        cout<<"Biggest number: "<<tempa[0]<<endl;
        //PRINTING THE HEART OF THE PYRAMID!
        if(l%2==0){
            cout<<"Heart of the pyramid: "<<heart<<" "<<heart;
        }
        else{
            cout<<"Heart of the pyramid: "<<heart;
        }
    }

    return 0;
}
//THE ARRAY SWAPING FUNCTION FOR THE ITERATION BETWEEN THE LETTERS.
void swap(int a[],int b[],int size){
    for(int i=0;i<size;i++){
        a[i]=b[i];
    }
}
//THE ARRAY PRINT FUNCTION!
void print(int a[],int size){
    for(int j=0;j<size;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}