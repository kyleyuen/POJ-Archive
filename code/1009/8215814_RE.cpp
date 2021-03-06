#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector< vector<int> >& constuct_image(vector< vector<int> >& image, int width, vector< pair<int, int> >& facilitate);
vector< vector<int> >& detect_image(vector< vector<int> >& image, int width, vector< vector<int> >& detected_image);
vector< pair<int, int> >& image_to_pairs(vector< vector<int> >& image, int width, vector< pair<int, int> >& facilitate, vector< pair<int, int> >& pairs);

int main()
{
    int width;    
    
    while (cin >> width) {
        if (width == 0) {
            break;
        }
        vector< vector<int> > image;
        vector< pair<int, int> > facilitate;
        
        constuct_image(image, width, facilitate); 
               
        vector< vector<int> > detected_image(image);
        detect_image(image, width, detected_image);
        
        vector< pair<int, int> > pairs;
        image_to_pairs(detected_image, width, facilitate, pairs);
        
        cout << width << endl;
        for (vector< pair<int, int> >::size_type n = 0; n != pairs.size(); ++n) {
            cout << pairs[n].first << ' ' << pairs[n].second << endl;
        }
    }
    cout << '0' << endl;
    
    return 0;
}

vector< vector<int> >& constuct_image(vector< vector<int> >& image, int width, vector< pair<int, int> >& facilitate)
{
    pair<int, int> pixel;
    vector<int> vec(width);
    int row = 0;
    vector<int>::size_type column = 0;
    
    while (cin >> pixel.first >> pixel.second) {
        if (pixel.first == 0 && pixel.second == 0) {
            break;
        }
        if (pixel.second > 4 * width) {
            int remain = pixel.second - 4 * width;
            pixel.second -= remain;
            
            pair<int, int> p;
            p.first = row + 2;
            p.second = remain;
            facilitate.push_back(p);
        }
        for (int i = 0; i != pixel.second; ++i) {
            vec[column] = pixel.first;
            ++column;
            if (column == width) {
                image.push_back(vec);
                column = 0;
                ++row;
            }
        }
    }
    if (column != 0) {
        image.push_back(vec);
    }
    return image;
}

vector< vector<int> >& detect_image(vector< vector<int> >& image, int width, vector< vector<int> >& detected_image)
{
    for (vector< vector<int> >::size_type i = 0, row = image.size(); i != image.size(); ++i) {
        for (vector<int>::size_type j = 0; j != image[0].size(); ++j) {
            int up = 0, right = 0, down = 0, left = 0;
            int north_west = 0, north_east = 0, south_east = 0, south_west = 0;
            
            if (i != 0) {
                up = abs(image[i][j] - image[i - 1][j]);
                if (j != 0) {
                    north_west = abs(image[i][j] - image[i - 1][j - 1]);
                }
                if (j != width - 1) {
                    north_east = abs(image[i][j] - image[i - 1][j + 1]);
                }
            }
            
            if (j != width - 1) {
                right = abs(image[i][j] - image[i][j + 1]);
            }
            if (j != 0) {
                left = abs(image[i][j] - image[i][j - 1]);
            }
            
            if (i != row - 1) {
                down = abs(image[i][j] - image[i + 1][j]);
                if (j != 0) {
                    south_west = abs(image[i][j] - image[i + 1][j - 1]);
                }
                if (j != width - 1) {
                    south_east = abs(image[i][j] - image[i + 1][j + 1]);
                }
            }
            
            int m1, m2, m3, m4, m5, m6, m;
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

vector< pair<int, int> >& image_to_pairs(vector< vector<int> >& image, int width, vector< pair<int, int> >& facilitate, vector< pair<int, int> >& pairs)
{
    int number;
    int count = 0;
    
    number = image[0][0];
    for (vector< vector<int> >::size_type i = 0, n = 0; i != image.size(); ++i) {
        if (facilitate.size() != 0) {
            if (i == facilitate[n].first) {
                count += facilitate[n].second;
                ++n;
            }
        }
        
        for (vector<int>::size_type j = 0; j != image[0].size(); ++j) {
            if (number == image[i][j]) {
                ++count;
            }
            else {
                pairs.push_back(make_pair(number, count));
                number = image[i][j];
                count = 1;
            }
        }
    }
    
    pairs.push_back(make_pair(number, count));
    pairs.push_back(make_pair(0, 0));
    return pairs;
}