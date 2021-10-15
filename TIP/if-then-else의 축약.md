```C++
#include 
using namespace std;

int mytype(int val){
    vector< int > interval {0, 15, 61, 100, 200} ;  // 요게 핵심
    int type = 0 ;
    for(int cut: interval){
        if( val < cut ) return( type);
        else type++ ;
    }
}  // end of mytype( )


int main() {
    vector  din { 23, -9, 44, 67, 103, 22, 16, 78} ;
    int code ;

    for( int w : din ){
        code =   mytype( w ) ;        cout << "\n w = "<< w ;;
        switch ( code ) {          // switch를 사용하자...제발 multiple branch할 때는말이다....엥....
            case 0 :  cout << " Error: 음수 나이 " ; break ;
            case 1 :  cout << " 어린이(Child) " ;     break ;
            case 2 :  cout << " 성인(Adult) " ;        break ;
            case 3 :  cout << " 노인(Old) " ;           break ;
            case 4 :  cout << " Error: 너무 많은 나이. 확인요망 " ; break ;
            default:  cout << " 이것 뭐여 ? 확인 바람 " ; break ;
        } // emd of switch( )
    } // end of for(w)

} // end of main()  by Zoh Q. - Professor
```
