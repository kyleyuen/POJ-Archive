#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector< vector<int> >& constuct_image(vector< vector<int> >& image, int width, vector<int>& facilitate);
vector< vector<int> >& detect_image(vector< vector<int> >& image, int width, vector< vector<int> >& detected_image);
vector< pair<int, int> >& image_to_pairs(vector< vector<int> >& image, int width, vector<int>& facilitate, vector< pair<int, int> >& pairs);

int main()
{
    int width;    
    
    while (cin >> width) {
        if (width == 0) {
            break;
        }
        vector< vector<int> > image;
        vector<int> facilitate;
        
        constuct_image(image, width, facilitate); 
               
        vector< vector<int> > detected_image(image);
        detect_image(image, width, detected_image);
        
        vector< pair<int, int> > pairs;
        image_to_pairs(detected_image, width, facilitate, pairs);
        
        for (vector< pair<int, int> >::size_type n = 0; n != pairs.size(); ++n) {
            cout << pairs[n].first << ' ' << pairs[n].second << endl;
        }
    }
    
    cout << '0' << endl;
    
    return 0;
}

vector< vector<int> >& constuct_image(vector< vector<int> >& image, int width, vector<int>& facilitate)
{
    pair<int, int> pixel;
    vector<int> vec(width);
    int row = 0;
    vector<int>::size_type column = 0;
    
    while (cin >> pixel.first >> pixel.second) {
        if (pixel.first == 0 && pixel.second == 0) {
            break;
        }
        if (pixel.second > 5 * width) {
            int remain = pixel.second - 5 * width;
            facilitate.push_back(row + 3);
            facilitate.push_back(remain);
            pixel.second -= remain;
        }
        for (int i = 0; i != pixel.second; ++i) {
            if (column == width) {
                image.push_back(vec);
                column = 0;
                ++row;
            }
            vec[column] = pixel.first;
            ++column;
        }
    }
    image.push_back(vec);
    return image;
}

vector< vector<int> >& detect_image(vector< vector<int> >& image, int width, vector< vector<int> >& detected_image)
{
    for (vector< vector<int> >::size_type row = image.size(), i = 0; i != row; ++i) {
        for (vector<int>::size_type j = 0; j != width; ++j) {
            int up = 0, right = 0, down = 0, left = 0;
            int north_east = 0, south_east = 0, south_west = 0, north_west = 0;
            int m1, m2, m3, m4, m5, m6, m;
            
            if (i != 0) {
                up = abs(image[i][j] - image[i - 1][j]);
                if (j != width - 1) {
                    north_east = abs(image[i][j] - image[i - 1][j + 1]);
                }
            }
            if (j != width - 1) {
                right = abs(image[i][j] - image[i][j + 1]);
                if (i != row - 1) {
                    north_west = abs(image[i][j] - image[i + 1][j + 1]);
                }
            }
            if (i != row - 1) {
                down = abs(image[i][j] - image[i + 1][j]);
                if (j != 0) {
                    south_west = abs(image[i][j] - image[i + 1][j - 1]);
                }
            }
            if (j != 0) {
                left = abs(image[i][j] - image[i][j - 1]);
                if (i != 0) {
                    south_east = abs(image[i][j] - image[i - 1][j - 1]);
                }
            }
            
            m1 = max(up, down);
            m2 = max(left, right);
            m3 = max(m1, m2);
            m4 = max(north_east, north_west);
            m5 = max(south_east, south_west);
            m6 = max(m4, m5);
            m = max(m3, m6);
            detected_image[i][j] = m;
        }
    }
    return detected_image;
}

vector< pair<int, int> >& image_to_pairs(vector< vector<int> >& image, int width, vector<int>& facilitate, vector< pair<int, int> >& pairs)
{
    int number;
    int count = 0;
    bool judge = false;
    
    if (facilitate.size() != 0) {
        judge = true;
    }
    number = image[0][0];
    for (vector< vector<int> >::size_type i = 0, n = 0; i != image.size(); ++i) {
        if (judge && i == facilitate[n]) {
            ++n;
            count += facilitate[n++];
        }
        for (vector<int>::size_type j = 0; j != width; ++j) {
            if (number == image[i][j]) {
                ++count;
            }
            else {
                pairs.push_back(make_pair(number, count));
                count = 1;
                number = image[i][j];
            }
        }
    }
    pairs.push_back(make_pair(number, count));
    pairs.push_back(make_pair(0, 0));
    return pairs;
}