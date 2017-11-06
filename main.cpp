/** Least squares of linear regression
 *
 * Martina Nunvarova
 * 25/9/2017
 */

///includes
#include <iostream>
#include <iomanip>
///namespace
using namespace std;


int main()
{
    char suffix[10][3]={"th","st","nd","rd","th","th","th","th","th","th"}; ///the counting suffixes

    double points[100][2];      ///the point array
    ///other variables
    int n=0;
    double sx=0,sy=0,sxy=0,sxx=0,ax=0,ay=0,m,c;

    ///Prompt the user
    cout<<"Lease Squares of Linear Regression"<<endl<<endl;
    cout<<"Points P[x,y] in the form of 'X_Val <space> Y_Val': "<<endl;
    cout << "How many points would you like to enter: ";
    ///get the amount of points to be entered
    cin >> n;

    if (n<2) {
        cout << "Well, THAT considered, we're done here..." << endl;
        return(0);
    }

    ///get all the points
    for (int i=0;i<n;i++) {
        cout <<i+1<<suffix[((i+1)<21 && (i+1)>3)?0:((i+1)%10)]<<" point:";  ///prompt user
        cin >>points[i][0] >>points[i][1];                                  ///get values

        sx+=points[i][0];                                                   ///calculate all the sums and averages
        sy+=points[i][1];
        sxy+=points[i][0]*points[i][1];
        sxx+=points[i][0]*points[i][0];
        ax+=points[i][0]/(float)n;
        ay+=points[i][1]/(float)n;
    }

    ///calculate the slope and y intercept
    m=(n*sxy-sx*sy)/(float)(n*sxx-sx*sx);
    c=ay-m*ax;

    ///print the results
    cout << sx <<endl<<sy<<endl<<sxy<<endl;
    cout << "The resulting linear approximation is: y="<<m<<" * x + "<<c << endl;

    ///return to OS, no errors
    return 0;
}
