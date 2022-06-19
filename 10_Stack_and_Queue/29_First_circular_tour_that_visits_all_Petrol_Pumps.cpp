// Thi sis the very easy solution written by me but giving TLE.

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
       for(int i=0; i<n; i++){
           int pet = p[i].petrol; int dist = p[i].distance;
    
           if(pet < dist){
               continue;
           }
           else{
               int j= i+1; pet -= dist;
               while(j%n != i){
                   
                   pet += p[j%n].petrol;
                   pet -= p[j%n].distance;
                   
                   if(pet < 0){
                       break;
                   }
                   j++;
               }
               
               if(j%n == i){
                   return i;
               }
           }
       }
       
       return -1;
    }
};


// more easy approach

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
        int osum = 0; int csum = 0; int j = 0;
        
       for(int i=0; i<n; i++){
           osum += (p[i].petrol - p[i].distance);
           csum += (p[i].petrol - p[i].distance);
           
           if(csum < 0){
               j = i+1;
               csum = 0;
           }
           
       }
       
       if(osum < 0){
           return -1;
       }
       return j;
    }
};
