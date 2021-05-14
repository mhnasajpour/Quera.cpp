class Cache
{
protected:
   //data structure
   int cp;                         //capacity
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0;       //get function
};