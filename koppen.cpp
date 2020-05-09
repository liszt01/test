//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

//container util
//------------------------------------------
#define all(a)  (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair

//repetition
//------------------------------------------
#define rep(i,n)  for(int i=0;i<(n);i++)




int main(){ //ケッペンの気候区分
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
    int forest, coldest_temp, warmest_temp, annual_precip, minimum_precip_month, maximum_precip_month;
    
    cout<<"樹林があるなら1，ないなら0を答えてください"<<endl;
    cin>>forest;
    
    if(forest){
        cout<<"最寒月平均気温[℃]を教えてください"<<endl;
        cin>>coldest_temp;
        
        if(coldest_temp>=18){ //熱帯
            cout<<"A 熱帯です"<<endl;
            cout<<"年降水量[mm]を教えてください"<<endl;
            cin>>annual_precip;
            cout<<"最小雨月降水量[mm]を教えてください"<<endl;
            cin>>minimum_precip_month;
            
            if(minimum_precip_month>=60){ //熱帯雨林気候
                cout<<"Af 熱帯雨林気候です．年中多雨で乾季なし"<<endl;
                return 0;
            }else if(25*minimum_precip_month+annual_precip>=2500){ //熱帯モンスーン気候
                cout<<"Am 熱帯モンスーン気候です．弱い乾季あり"<<endl;
                return 0;
            }else{ //サバナ気候
                cout<<"Aw サバナ気候です．冬乾燥"<<endl;
                return 0;
            }
            
            
        }else if(coldest_temp>=-3){ //温帯
            int minimum_precip_month2, maximum_precip_month2;
            cout<<"C 温帯です"<<endl;
            cout<<"夏の最小雨月降水量[mm]を教えてください"<<endl;
            cin>>minimum_precip_month;
            cout<<"冬の最多雨月降水量[mm]を教えてください"<<endl;
            cin>>maximum_precip_month;
            cout<<"冬の最小雨月降水量[mm]を教えてください"<<endl;
            cin>>minimum_precip_month2;
            cout<<"夏の最多雨月降水量[mm]を教えてください"<<endl;
            cin>>maximum_precip_month2;
            
            if(minimum_precip_month*3<=maximum_precip_month){ //最小雨月が夏
                cout<<"Cs 地中海性気候です．夏乾燥"<<endl;
                return 0;
            }else if(minimum_precip_month2*10<=maximum_precip_month2){ //最小雨月が冬
                cout<<"Cw 温暖冬季少雨気候です．冬乾燥"<<endl;
                return 0;
            }else{ //年中多雨
                cout<<"最暖月平均気温を教えてください"<<endl;
                cin>>warmest_temp;
                
                if(warmest_temp>=22){ //温暖湿潤気候
                    cout<<"Cfa 温暖湿潤気候です．年中湿潤"<<endl;
                    return 0;
                }else{ //西岸海洋性気候
                    cout<<"Cfb 西岸海洋性気候です．年中湿潤"<<endl;
                    return 0;
                }
            }
        
        }else{ //亜寒帯
            cout<<"D  亜寒帯です"<<endl;
            cout<<"冬の最小雨月降水量[mm]を教えてください"<<endl;
            cin>>minimum_precip_month;
            cout<<"夏の最多雨月降水量[mm]を教えてください"<<endl;
            cin>>maximum_precip_month;
            
            if(minimum_precip_month*10<=maximum_precip_month){ //亜寒帯冬季少雨気候
                cout<<"Dw 亜寒帯冬季少雨気候です．冬乾燥"<<endl;
                return 0;
            }else{ //亜寒帯湿潤気候
                cout<<"Df 亜寒帯湿潤気候です．年中湿潤"<<endl;
                return 0;
            }
        }
    }else{ //森林限界
        cout<<"最暖月平均気温[℃]を教えてください"<<endl;
        cin>>warmest_temp;
        
        if(warmest_temp<0){ //氷雪気候
            cout<<"EF 氷雪気候です"<<endl;
            return 0;
        }else if(warmest_temp<10){ //ツンドラ気候
            cout<<"ET ツンドラ気候です"<<endl;
            return 0;
            
        }else{ //乾燥帯
            int minimum_precip_month2, maximum_precip_month2, annual_temp, dry_limit;
            cout<<"B 乾燥帯です"<<endl;
            cout<<"夏の最小雨月降水量[mm]を教えてください"<<endl;
            cin>>minimum_precip_month;
            cout<<"冬の最多雨月降水量[mm]を教えてください"<<endl;
            cin>>maximum_precip_month;
            cout<<"冬の最小雨月降水量[mm]を教えてください"<<endl;
            cin>>minimum_precip_month2;
            cout<<"夏の最多雨月降水量[mm]を教えてください"<<endl;
            cin>>maximum_precip_month2;
            
            if(minimum_precip_month*3<=maximum_precip_month){ //夏乾燥
                cout<<"年平均気温[℃]を教えてください"<<endl;
                cin>>annual_temp;
                
                dry_limit = 20 * annual_temp;
                
                if(dry_limit/2<=annual_temp){ //ステップ気候
                    cout<<"BS ステップ気候です"<<endl;
                    return 0;
                }else{ //砂漠気候
                    cout<<"BW 砂漠気候です"<<endl;
                    return 0;
                }
            }else if(minimum_precip_month2*10<=maximum_precip_month2){ //冬乾燥
                cout<<"年平均気温[℃]を教えてください"<<endl;
                cin>>annual_temp;
                
                dry_limit = 20 * (annual_temp+14);
                
                if(dry_limit/2<=annual_temp){ //ステップ気候
                    cout<<"BS ステップ気候です"<<endl;
                    return 0;
                }else{ //砂漠気候
                    cout<<"BW 砂漠気候です"<<endl;
                    return 0;
                }
            }else{ //乾季なし
                cout<<"年平均気温[℃]を教えてください"<<endl;
                cin>>annual_temp;
                
                dry_limit = 20 * (annual_temp+7);
                
                if(dry_limit/2<=annual_temp){ //ステップ気候
                    cout<<"BS ステップ気候です"<<endl;
                    return 0;
                }else{ //砂漠気候
                    cout<<"BW 砂漠気候です"<<endl;
                    return 0;
                }
            }
        }
    }
}
