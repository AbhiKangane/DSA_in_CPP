// Input: Given string s contains char only a-z, A-Z, 0-9

// For decoding the string convert string into matrix of dimension N*M 
// Where N = floor value of sqrt(s.size()) & M = ceil value of sqrt(s.size())
// insert all chars from string into matrix & if some cells are free in matrix then add empty string in that cell

// Output : 
// Single string contains space seperated word formed by column traversal of each column in matrix

// Note: Don't print extra space
// 1 <= s.size() <= 2000 

// Example 1: 
// Input :
// s = "abcdefgh"          s.size() = 8
// output : ad be cf
// explaination :
// mat(2*3) = a b c
//            d e f

// Example 2
// s = "abcdefghijklmnopqr"  s.size() = 18
// output : afkp bglq chmr din ejo
// explaination :
// mat(4*5) = a b c  d   e
//            f g h  i   j
//            k l m  n   o
//            p q r  '$' '$'


#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int row = floor(sqrt(s.size()));
    int col = ceil(sqrt(s.size()));
    cout<<endl<<s.size()<<" "<<row*col<<endl;

    // sol 1  : works
    string ans = "";
    for(int i=0; i<col; i++){
        string temp = "";
        for(int j=i; j<s.size(); j+=col)
            if(j<row*col)
                temp += s[j];
        ans += temp;
        if(i!=col-1)
            ans+=" ";
    }

    // sol 2
    // string ans="";
    // vector<vector<char>> mat(row, vector<char>(col));
    // int x=0;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         if(x < s.size()){
    //             mat[i][j] = s[x];
    //             x++;
    //         }
    //         else
    //             mat[i][j] = '$';  // for empty cell
    //     }
    // }

    // for(int j=0; j<col; j++){
    //     string temp = "";
    //     for(int i=0; i<row; i++){
    //         if(mat[i][j] != '$')
    //             temp += mat[i][j];
    //     }
    //     ans += temp;
    //     if(j!=col-1)
    //         ans += " ";
    // }

    cout<<ans;
    return 0;
}


// abjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGRYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnngHJTyrTRTRbnBBCgdRErBCVbdrgERYuIUbmnvBBffSEQreGcbMJYtrw2XWEREghHhghffgFEVBCfdDgNhfhGabjbfdsbslbduhjhjhlkuKGKgBGHJjfjBkjfut3589886IGjgtevhCTHHSy698UbvgnDGRerE4DhVHfTT23ccbXMhgjfTEDsfGbnvmJu635fVVnn