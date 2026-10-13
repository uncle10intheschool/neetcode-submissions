/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1; int r = n;
        while (l <= n){
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            int res1 = guess(m1);
            int res2 = guess(m2);
            if (res1 == 0) return m1;
            if (res2 == 0) return m2;
            
            if (res1 + res2 == 0){ // (m1;m2)
                l = m1+1;
                r = m2-1;
            } else if (res1 == -1){
                r = m1-1;
            } else l = m2+1;
        }
        return l;
    }
};