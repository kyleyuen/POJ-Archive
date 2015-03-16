#include <iostream>

using namespace std;

bool solve();

int main()
{
    while (solve());
    return 0;
}

bool solve()
{
    int product[6];
    cin >> product[0] >> product[1] >> product[2] >> product[3] >> product[4] >> product[5];
    if (product[0] == 0 && product[1] == 0 && product[2] == 0 && product[3] == 0 && product[4] == 0 && product[5] == 0) {
        return false;
    }
    
    int packets = product[5];
    while (product[4] != 0) {
        --product[4];
        ++packets;
        product[0] = (product[0] > 11) ? product[0] - 11 : 0;
    }
    while (product[3] != 0) {
        --product[3];
        ++packets;
        if (product[1] > 5) {
            product[1] -= 5;
        }
        else {
            int remain_space = 20 - 4 * product[1];
            product[1] = 0;
            product[0] = (product[0] > remain_space) ? product[0] - remain_space : 0;
        }
    }
    if (product[2] != 0) {
        packets += product[2] / 4;
        product[2] %= 4;
        if (product[2] != 0) {
            ++packets;
            int remain_space = 36 - product[2] * 9;
            switch (product[2]) {
            case 1:
                if (product[1] >= 5) {
                    product[1] -= 5;
                    remain_space -= 20;
                }
                else {
                    remain_space -= 4 * product[1];
                    product[1] = 0;
                }
                break;
            case 2:
                if (product[1] >= 2) {
                    product[1] -= 2;
                    remain_space -= 8;
                }
                else {
                    remain_space -= 4 * product[1];
                    product[1] = 0;
                }
                break;
            case 3:
                if (product[1] >= 1) {
                    --product[1];
                    remain_space -= 4;
                }
                break;
            }
            product[0] = (product[0] > remain_space) ? product[0] - remain_space : 0;
        }
    }
    if (product[1] != 0) {
        packets += product[1] / 9;
        product[1] %= 9;
        if (product[1] != 0) {
            ++packets;
            int remain_space = 36 - product[1] * 4;
            product[0] = (product[0] > remain_space) ? product[0] - remain_space : 0;
        }
    }
    if (product[0] != 0) {
        packets += product[0] / 36;
        product[0] %= 36;
        if (product[0] != 0) {
            ++packets;
        }
    }
    cout << packets << endl;
    return true;
}
