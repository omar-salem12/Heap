#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Heap {
private:
      vector<T> bt;

      void siftUp(int i) {
          if(!i) return;
          int p = (i-1)/2;
          if(bt[p] > bt[i]) {
             swap(bt[i],bt[p]);
             siftUp(p);

          }


      }  // end siftUp helper method
         void siftDown(int i) {
         int mn;
            int lf = 2*i+1,rt = 2*i+2;
            if (lf >= bt.size()) return;
             if(rt >= bt.size() || bt[lf] < bt[rt]) mn = lf;
             else
                mn = rt;
            if(bt[i] <bt[mn]) return;
            T tmp = bt[i];
            bt[i] = bt[mn];
            bt[mn] = tmp;
            siftDown(mn);

      }  // end siftDown function.

       void heapify() {

            for (int i = ((int) bt.size()-2) / 2; i >= 0; --i)
               siftDown(i);
         }

      public:
         Heap() {}

         Heap(const vector<T> &vec) {
           bt =vec;
           heapify();
         }

        void Insert(const T& val) {
           bt.push_back(val);
           siftUp(bt.size()-1);
        }
         void removeMin() {
            swap(bt[0],bt.back());
            bt.pop_back();
            siftDown(0);
         }

          T Min() {
             return bt[0];
          }






};





int main()
{

   Heap<int> h;
   h.Insert(3);
   h.Insert(6);
   h.Insert(8);
   h.Insert(9);
   h.Insert(2);
  cout<< h.Min();
   return 0;
}
