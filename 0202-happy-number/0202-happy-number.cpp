class Solution {
public:

    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum = sum + digit * digit;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        while (true) {

            slow = getNext(slow);
            fast = getNext(getNext(fast));

            if (slow == fast)
                break;
        }

        return slow == 1;
    }
};