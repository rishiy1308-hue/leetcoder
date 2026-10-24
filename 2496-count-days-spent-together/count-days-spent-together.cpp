class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(stoi(arriveAlice.substr(0, 2)) * 100 + stoi(arriveAlice.substr(3, 2)),
                        stoi(arriveBob.substr(0, 2)) * 100 + stoi(arriveBob.substr(3, 2)));

        int end = min(stoi(leaveAlice.substr(0, 2)) * 100 + stoi(leaveAlice.substr(3, 2)),
                      stoi(leaveBob.substr(0, 2)) * 100 + stoi(leaveBob.substr(3, 2)));

        if (start > end) return 0;

        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int startMonth = start / 100;
        int startDay = start % 100;
        int endMonth = end / 100;
        int endDay = end % 100;

        int startCount = startDay;
        for (int i = 1; i < startMonth; i++) {
            startCount += days[i];
        }

        int endCount = endDay;
        for (int i = 1; i < endMonth; i++) {
            endCount += days[i];
        }

        return endCount - startCount + 1;
    }
};