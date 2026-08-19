class Solution {
public:
    void mark(int row, int j, int k, unordered_map<int, vector<int>>& seats) {
        for(int i = j; i <= k; i++) {
            seats[row][i] = 1;
        }
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, vector<int>> seats;
        for(auto &r : reservedSeats) {
            int row = r[0] - 1;
            int col = r[1] - 1;
            if(seats.find(row) == seats.end()) {
                seats[row] = vector<int>(10, 0);
            }

            seats[row][col] = 1;
        }

        int fam = 0;

        // Rows which have NO reservation
        // can accommodate 2 families each
        fam += (n - seats.size()) * 2;

        // Process only rows having reservations
        for(auto &it : seats) {

            int row = it.first;

            int cnt1 = 0, cnt2 = 0, cnt3 = 0;

            // seats 2-5
            for(int j = 1; j <= 4; j++) {
                if(seats[row][j] == 0)
                    cnt1++;
                else
                    break;
            }

            if(cnt1 == 4) {
                fam++;
                mark(row, 1, 4, seats);
            }

            // seats 4-7
            for(int j = 3; j <= 6; j++) {
                if(seats[row][j] == 0)
                    cnt2++;
                else
                    break;
            }

            if(cnt2 == 4) {
                fam++;
                mark(row, 3, 6, seats);
            }

            // seats 6-9
            for(int j = 5; j <= 8; j++) {
                if(seats[row][j] == 0)
                    cnt3++;
                else
                    break;
            }

            if(cnt3 == 4) {
                fam++;
                mark(row, 5, 8, seats);
            }
        }

        return fam;
    }
};