#include "Expenses.h"

Expenses::Expenses()
{
    userID = 0;
}

void Expenses::setUserID(int userID)
{
    this->userID = userID;
}

void Expenses::addNewExpense()
{
    char choice;
    string dateToSet;
    system("cls");
    cout << "What is the date of this expense?" <<endl;
    cout << "\n1. Today's date \n2. Another date\n3. Return to the main menu" << endl;
    cin >> choice;
    system("cls");
    do
    {
        switch(choice)
        {
        case '1':
            dateToSet = dateOperator.getTodaysStringDate();
            addNewExpense(dateToSet);
            choice = 3;
            break;
        case '2':
            cout << "Please enter the date (only yyyy-mm-dd format is accepted, e.g. 2018-02-17): " << endl;
            do
            {
                cin >> dateToSet;
                if(dateToSet == "back")
                {
                    choice = 3;
                    break;
                }
                if(!dateOperator.validateDate(dateToSet))
                    cout << "The date is incorrect, please enter a proper date or \"back\" to return." << endl;
                else
                {
                    addNewExpense(dateToSet);
                    choice = 3;
                    break;
                }
            }
            while(!dateOperator.validateDate(dateToSet));
            break;
        case '3':
            break;
        default:
            cout << "Please press 1-3" << endl;
        }
    }
    while(choice == '3');
}
void Expenses::addNewExpense(string correctDate)
{
    Expense newExpense;
    newExpense.setStringDate(correctDate);
    newExpense.setIntDate(dateOperator.typeConversion.stringDateToInt(correctDate));

    string item, amount;

    cout << "\nPlease enter the source of your expense \n(shopping, fuel, rent etc.) " << endl;
    cin.sync();
    getline(cin, item);
    newExpense.setItem(item);

    cout << "\nPlease enter the amount of this expense (e.g. 350.44)" << endl;
    cin >> amount;

    while(!amountOperator.checkAmount(amount))
    {
        cout << "The amount is incorrect, please enter the amount again" << endl;
        cout << "You can only use numbers and one dot (or one comma) " << endl;
        cin >> amount;
    }
    newExpense.setAmount(atof(amount.c_str()));

    if(expensesFile.expensesVector.size() == 0)
        newExpense.setExpenseID(1);
    else
        newExpense.setExpenseID(expensesFile.expensesVector.back().getExpenseID()+1);

    newExpense.setUserID(userID);

    char choice;
    cout << "Are you sure to add the expense? Press 'y' to confirm: ";
    cin >> choice;
    if(choice == 'y')
    {
        expensesFile.addExpense(newExpense);
        cout << "\nNew expense has been added successfully" << endl;
    }
    else cout << "\nWe return to the main menu without adding expense";
    Sleep(1500);


}

double Expenses::showExpensesOfCurrentMonth()
{
    double totalExpenses = 0;

    if(!expensesFile.expensesVectorSortedByDate)
        sortExpensesByDate();

    int intDateOfFirstDayOfThisMonth = (dateOperator.todaysIntDate - dateOperator.thisDay) + 1;

    vector <Expense> ::iterator itr, endOfVector = expensesFile.expensesVector.end( );
    for(itr = expensesFile.expensesVector.begin(); itr != endOfVector; ++itr)
    {
        if(itr->getIntDate() >= intDateOfFirstDayOfThisMonth)
        {
            cout << itr->getStringDate() <<" |" << setw(11)<<fixed<<setprecision(2) << itr->getAmount()<< " | "<< itr->getItem() << endl;
            totalExpenses += itr->getAmount();
        }
    }
    return totalExpenses;
}

double Expenses::showExpensesOfPreviousMonth()
{
    double totalExpenses = 0;

    if(!expensesFile.expensesVectorSortedByDate)
        sortExpensesByDate();

    int dateOfTheFirstDayOfPreviousMonth = dateOperator.returnIntDateOfFirstDayOfPreviousMonth();
    int dateOfTheLastDayOfPreviousMonth = dateOperator.returnIntDateOfTheLastDayOfPreviousMonth();

    vector <Expense> ::iterator itr, endOfVector = expensesFile.expensesVector.end( );
    for(itr = expensesFile.expensesVector.begin(); itr != endOfVector; ++itr)
    {
        if(itr->getIntDate() >= dateOfTheFirstDayOfPreviousMonth && itr->getIntDate() <= dateOfTheLastDayOfPreviousMonth)
        {
            cout << itr->getStringDate() <<" |" << setw(11)<<fixed<<setprecision(2) << itr->getAmount()<< " | "<< itr->getItem() << endl;
            totalExpenses += itr->getAmount();
        }
    }
    return totalExpenses;
}

double Expenses::showExpensesOfSelectedPeriod(string stringDateFrom, string stringDateTo)
{
    double totalExpenses = 0;

    if(!expensesFile.expensesVectorSortedByDate)
        sortExpensesByDate();

    int fromDate = dateOperator.typeConversion.stringDateToInt(stringDateFrom);
    int toDate = dateOperator.typeConversion.stringDateToInt(stringDateTo);

    vector <Expense> ::iterator itr, endOfVector = expensesFile.expensesVector.end( );
    for(itr = expensesFile.expensesVector.begin(); itr != endOfVector; ++itr)
    {
        if (itr->getIntDate() >= fromDate && itr->getIntDate() <= toDate)
        {
            cout << itr->getStringDate() <<" |" << setw(11)<<fixed<<setprecision(2) << itr->getAmount()<< " | "<< itr->getItem() << endl;
            totalExpenses += itr->getAmount();
        }
    }
    return totalExpenses;
}


bool Expenses::sortExpensesByDate()
{
    sort( expensesFile.expensesVector.begin(), expensesFile.expensesVector.end( ), [ ](Expense& expense1, Expense& expense2 )
    {
        return expense1.getIntDate() < expense2.getIntDate();
    });
    expensesFile.expensesVectorSortedByDate = true;
}
