#include "Incomes.h"

Incomes::Incomes()
{
    userID = 0;
    totalIncome = 0;
}
void Incomes::setUserID(int userID)
{
    this->userID = userID;
}
void Incomes::addNewIncome()
{
    char choice;
    string dateToSet;
    system("cls");
    cout << "What is the date of this income?" <<endl;
    cout << "\n1. Today's date \n2. Another date\n3. Return to the main menu" << endl;
    cin >> choice;
    system("cls");
    do
    {
        switch(choice)
        {
        case '1':
            dateToSet = dateOperator.getTodaysStringDate();
            addNewIncome(dateToSet);
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
                    addNewIncome(dateToSet);
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

void Incomes::addNewIncome(string correctDate)
{
    Income newIncome;
    newIncome.setDate(dateOperator.typeConversion.stringDateToInt(correctDate));

    string item, amount;

    cout << "\nPlease enter the source of your income \n(payment, money prize, sale on ebay, etc.) " << endl;
    cin.sync();
    getline(cin, item);
    newIncome.setItem(item);

    cout << "\nPlease enter the amount of this income (e.g. 350.44)" << endl;
    cin >> amount;

    while(!amountOperator.checkAmount(amount))
    {
        cout << "The amount is incorrect, please enter the amount again" << endl;
        cout << "You can only use numbers and one dot (or one comma) " << endl;
        cin >> amount;
    }
    newIncome.setAmount(atof(amount.c_str()));

    if(incomesFile.incomesVector.size() == 0)
        newIncome.setIncomeID(1);
    else
        newIncome.setIncomeID(incomesFile.incomesVector.back().getIncomeID()+1);

    newIncome.setUserID(userID);
    char choice;
    cout << "Are you sure to add the income? Press 'y' to confirm: ";
    cin >> choice;
    if(choice == 'y')
    {
        incomesFile.addIncome(newIncome);
        cout << "\nNew income has been added successfully" << endl;
    }
    else cout << "\nWe return to the main menu without adding income";
    Sleep(1500);
}

double Incomes::getTotalIncome()
{
     return totalIncome;
}

void Incomes::showIncomes(vector <Income> &incomes)
{
    totalIncome = 0;

     vector<Income> ::iterator itr, endOfVector = incomes.end();

     for(itr = incomes.begin(); itr != endOfVector; ++itr)
        {

        cout << dateOperator.returnStringDate(itr->getDate()) <<" |" << setw(11)<<fixed
             << setprecision(2) << itr->getAmount()<< " | "<< itr->getItem() << endl;

        totalIncome += itr->getAmount();
        }
}

vector <Income> Incomes::returnSelectedIncomes(int dateFrom)
{
    vector <Income> selectedIncomes;
    int length = incomesFile.incomesVector.size();

    if(!incomesFile.isIncomesVectorSortedByDate)
        incomesFile.sortIncomesByDate();

    for(int i = 0; i < length; i++)
         if(incomesFile.incomesVector[i].getUserID() == userID && incomesFile.incomesVector[i].getDate() >= dateFrom )
            selectedIncomes.push_back(incomesFile.incomesVector[i]);

    return selectedIncomes;
}

vector <Income> Incomes::returnSelectedIncomes(int dateFrom, int dateTo)
{
    vector <Income> selectedIncomes;
    int length = incomesFile.incomesVector.size();

    if(!incomesFile.isIncomesVectorSortedByDate)
        incomesFile.sortIncomesByDate();

    for(int i = 0; i < length; i++)
         if(incomesFile.incomesVector[i].getUserID() == userID &&
            incomesFile.incomesVector[i].getDate() >= dateFrom && incomesFile.incomesVector[i].getDate() <= dateTo)
            selectedIncomes.push_back(incomesFile.incomesVector[i]);

    return selectedIncomes;
}

void Incomes::showIncomesOfCurrentMonth()
{
    int dateOfFirstDayOfThisMonth = (dateOperator.todaysIntDate - dateOperator.thisDay) + 1;

    vector <Income> currentMonthIncomes = returnSelectedIncomes(dateOfFirstDayOfThisMonth);
    showIncomes(currentMonthIncomes);
}

void Incomes::showIncomesOfPreviousMonth()
{
    int dateFrom = dateOperator.returnIntDateOfFirstDayOfPreviousMonth();
    int dateTo = dateOperator.returnIntDateOfTheLastDayOfPreviousMonth();

    vector <Income> previousMonthIncomes = returnSelectedIncomes(dateFrom, dateTo);

    showIncomes(previousMonthIncomes);
}

void Incomes::showIncomesOfSelectedPeriod(string stringDateFrom, string stringDateTo)
{
    int dateFrom = dateOperator.typeConversion.stringDateToInt(stringDateFrom);
    int dateTo = dateOperator.typeConversion.stringDateToInt(stringDateTo);

   vector <Income> selectedPeriodIncomes = returnSelectedIncomes(dateFrom, dateTo);

    showIncomes(selectedPeriodIncomes);
}



