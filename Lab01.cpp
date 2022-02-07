#include <iostream>
using namespace std;

void small_orders(int choclate_order, int& large_order, int& medium_order, int& small_order) {
    int stock_l = 150;

    if (choclate_order % 5 == 0) {
        large_order = stock_l - (stock_l - (choclate_order) / 5);
    }
    else {
        int difference = choclate_order % 5;
        large_order = stock_l - (stock_l - (choclate_order - difference) / 5);
        std::cout << "difference" << difference << std::endl;
        if (difference >= 3) {
            medium_order = 1;
            small_order = difference - 3;
        }
        else {
            small_order = difference;
        }
    }
}

void medium_orders(int choclate_order, int& medium_order, int& small_order) {
    int stock_m = 120;
    if (choclate_order % 3 == 0) {
        medium_order = stock_m - (stock_m - (choclate_order) / 3);
    }
    else {
        int difference = choclate_order % 3;
        medium_order = stock_m - (stock_m - (choclate_order - difference) / 5);
        std::cout << "difference" << difference << std::endl;
        small_order = difference;

    }
}

int main() {
    std::cout << 150 * 5 << std::endl;
    std::cout << 120 * 3 << std::endl;
    int choclate_order;
    int large_order = 0, medium_order = 0, small_order = 0;
    int stock_s = 700;
    int stock_m = 120;
    int stock_l = 150;
    int total_lbs_of_choclate = stock_s + stock_m * 3 + stock_l * 5;
    cout << "Enter how many pounds of chocolated you would like? ";
    cin >> choclate_order;
    cout << choclate_order << std::endl;
    if (choclate_order < total_lbs_of_choclate) {
        if (choclate_order < (stock_l * 5)) {
            small_orders(choclate_order, large_order, medium_order, small_order);
        }
        else if (choclate_order <= (stock_l * 5) + (stock_m * 3)) {
            large_order = 150;
            medium_orders(choclate_order - (stock_l * 5), medium_order, small_order);
        }
        else {
            large_order = 150;
            medium_order = 120;
            small_order = choclate_order - ((stock_l * 5) + (stock_m * 3));
            
        }

    }
    else {
        cout << "Your order can't be filled" << endl;
    }
    std::cout << "Large Order " << large_order << std::endl;
    std::cout << "Medium Order " << medium_order << std::endl;
    std::cout << "Small Order " << small_order << std::endl;


    //cout << "Your order has been filled"


    /*tempL = chocolate/ 5;
    if (tempL > largechoc)
        tempL = largechoc;
    //find the left over amount
    tempS = chocolate - 5 * tempL;
    if (tempS > smallchoc)
        cout << "Sorry cant fufill this order " << endl;
    else {
        cout << "Your order has been filled " << endl;
        cout << " Small bars\n" << tempL  << endl;
        cout << " Medium bars\n" << tempL  << endl;
        cout << " Large bars\n" << tempL  << endl;
        cout << " = " << tempL * 5 + tempS << endl;  */


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
