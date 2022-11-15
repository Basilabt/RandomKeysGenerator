#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;


enum MenuChoice {
    Windows = 1 ,
    Steam = 2 ,
    Itunes = 3 ,
    GooglePlay = 4
};

// Dec.

void clearScreen(void);
void goBackToMainMenu(void);

void runProgram(void);
void printChoiceMenu(void);
void printScreenTitle(string);
short readOperation(void);
bool isValidOperation(short);
void performOperation(MenuChoice);

void windows(void);
short readNumberOfKeys(void);
bool isValidKeysNumber(short);
void makeSound(void);
void generateWindowsActivationKeys(short);
void printActivationKey(short,string);
string generateWindowsKey(void);
char getChar(void);
void appendDash(short,string&);
short generateRandomNumber(short,short);
char readConfirmationAnswer(short);

void steam(void);
void generateSteamGiftCardKeys(short);
string generateSteamGiftCardKey(void);

void itunes(void);
void generateItunesGiftCardKeys(short);
string generateItunesGiftCardKey(void);


void googlePlay(void);
void generateGooglePlayCardKeys(short);
string generateGooglePlayCardKey(void);




int main() {
    
    srand((unsigned)time(NULL));
    

    runProgram();
    
    return 0 ;
}

// Def.

void clearScreen() {
    system("cls");
}

void goBackToMainMenu() {
    cout << "\n\nPress Any Key To Go Back To Main Menu ..." << endl;
    system("system>0");
}

void runProgram() {
    
    clearScreen();
    
    printChoiceMenu();
    
    performOperation(MenuChoice(readOperation()));
    
}

void printChoiceMenu(void) {
    
    printScreenTitle("Activation Keys Generator");
    
    cout << "\t[1] Windows Activation Keys. " << endl;
    cout << "\t[2] Steam Cards. " << endl;
    cout << "\t[3] Itunes Gift Cards. " << endl;
    cout << "\t[4] Google Gift Cards. " << endl;
    cout << "==================================================================" << endl;
    
}

short readOperation() {
    
    short number = 0 ;
    
    do {
        cout << "Enter Your Choice ? ";
        cin >> number;
        cout << "\n";
    } while(!isValidOperation(number));
    
    return number;
}

bool isValidOperation(short number) {
    return number >= 1 ? number <= 4 : false;
}

void performOperation(MenuChoice choice) {
    
    clearScreen();
    
    switch (choice) {
            
        case MenuChoice::Windows:
            windows();
            break;
            
            
        case MenuChoice::Steam:
            steam();
            break;
            
            
        case MenuChoice::Itunes:
            itunes();
            break;
            
        
        case MenuChoice::GooglePlay:
            googlePlay();
            break;
            
            
    }
    
    goBackToMainMenu();
}

void windows() {

    printScreenTitle("Windows Active Key Generator");
    
    short numberOfKeys = readNumberOfKeys();
    
    if(toupper(readConfirmationAnswer(numberOfKeys)) == 'Y') {
        generateWindowsActivationKeys(numberOfKeys);
    }
    
  
        
}

void printScreenTitle(string title) {
    cout << "==================================================================" << endl;
    cout << "\t"<< title << endl;
    cout << "==================================================================" << endl;
}


short readNumberOfKeys() {
    
    short number = 0 ;
    
    cout << "Enter Number Of Keys To Generate  ? ";
    cin >> number;
    cout << "\n";
    
    while(!isValidKeysNumber(number)) {
        makeSound();
        cout << "Invalid Number , Enter Number Of Keys To Generate  ? ";
        cin >> number;
        cout << "\n";
    }
     
    
    return number;
}

bool isValidKeysNumber(short number) {
    return number >= 1 ? number <= 32000 : false;
}

void makeSound() {
    cout << "\a";
}


char readConfirmationAnswer(short numberOfKeys) {
    
    char answer = 'n';
    
    cout << "Are You Sure You Want To Generate " << numberOfKeys << " Activation Key ? [ Y | N ] ? ";
    cin >> answer;
    
    return answer;
}

void generateWindowsActivationKeys(short numberOfKeys) {
    
    cout << "\n\n";
    
    string key = "";
    
    for( short i=1 ; i<=numberOfKeys ; i++) {
        
        key = generateWindowsKey();
        
        printActivationKey(i,key);
        
    }
}

string generateWindowsKey() {
    
    // Windows Key: xxxxx - xxxxx - xxxxx - xxxxx - xxxxx
    
    const short keyCharachters = 25;
    
    string key = "";
    
    
    for(short i=1 ; i<= keyCharachters ; i++) {
        
        key += getChar();
        
        appendDash(i,key);
        
    }
    
    
    return key.substr(0,key.length()-1);
}

char getChar() {
    
    // A -- Z : ASCII ( 65 -- 90 )
    // 0 -- 9 : ASCII ( 48 -- 57 )
    
    // random Number To Choose Between a Char or Number.
    // between ( 0 & 4 ) 3 even numbers that means more probability to get a char over a number.
    short randomNumber = generateRandomNumber(0,4);
    
    return (randomNumber%2==0) ? char(generateRandomNumber(65,90)) : char(generateRandomNumber(48,57));
    
}

short generateRandomNumber(short from , short to) {
    return rand() % ( to - from + 1 ) + from ;
}

void appendDash(short charNumber , string& key) {
    if(charNumber % 5 == 0)
        key += "-";
}

void printActivationKey(short number , string key) {
    cout << left << setw(2) << number << ") " << "Activation Key: " << key << endl;
}

void steam() {
    
    printScreenTitle("Steam Gift card Keys Generator");
    
    short numberOfKeys = readNumberOfKeys();
    
    if(toupper(readConfirmationAnswer(numberOfKeys)) == 'Y') {
        generateSteamGiftCardKeys(numberOfKeys);
    }
    
    cout << "\nPress Any Key To Exit" << endl;
    system("pause>0");
}


void generateSteamGiftCardKeys(short numberOfKeys) {
    
    cout << "\n\n";
    
    string key = "";
    
    for(short i = 1 ; i<=numberOfKeys ; i++) {
        
        key = generateSteamGiftCardKey();
        
        printActivationKey(i,key);
    }
     
}


string generateSteamGiftCardKey() {
    
    // Steam Key: xxxxx - xxxxx - xxxxx
    
    const short steamKeyLength = 15 ;
    
    string key = "";
    
    
    for(short i=1 ; i<=steamKeyLength ; i++) {
        key += getChar();
        appendDash(i,key);
    }
        
    
    return key.substr(0,key.length()-1);
}


void itunes() {
    
    printScreenTitle("Itunes Gift Card Key Generator");
    
    short numberOfKeys = readNumberOfKeys();
    
    
    if(toupper(readConfirmationAnswer(numberOfKeys)) == 'Y') {
        generateItunesGiftCardKeys(numberOfKeys);
    }
    
    
}


void generateItunesGiftCardKeys(short numberOfKeys) {
    
    string key = "";
    
    for(short i=1 ; i<=numberOfKeys ; i++) {
        
        key = generateItunesGiftCardKey();
        
        printActivationKey(i,key);
        
    }
    
}


string generateItunesGiftCardKey() {
    
    // Apple Key: xxxx - xxxxxx - xxxxx
    
    const short firstPortion = 4;
    const short secondPortion = 6;
    const short thirdPortion = 5;
    
    string key = "";
    
    // First Portion
    for(short i=1 ; i<=firstPortion ; i++)
        key += getChar();
    
    appendDash(0,key);
    
    
    // Second Portion
    for(short i=1 ; i<=secondPortion ; i++)
        key += getChar();
    
    appendDash(0,key);
    
    
    // Third Portion
    for(short i=1 ; i<=thirdPortion ; i++)
        key += getChar();
    
    
    
    return key;
}


void googlePlay() {
   
    printScreenTitle("Google Play Card Key Generator");
    
    short numberOfKeys = readNumberOfKeys();
    
    if(toupper(readConfirmationAnswer(numberOfKeys)) == 'Y') {
        generateGooglePlayCardKeys(numberOfKeys);
    }
    
    
}

void generateGooglePlayCardKeys(short numberOfKeys) {
    
    string key = "";
    
    
    for(short i=1 ; i<=numberOfKeys ; i++) {
        
        key = generateGooglePlayCardKey();
        
        printActivationKey(i,key);
        
    }
     
}


string generateGooglePlayCardKey() {
    
    // Google Play Key: xxxxx - xxxxx - xxxxx - xxxxx - xxxxx
    
    const short googlePlayKeyLength = 25;
    
    string key = "";
    
    
    for(short i=1 ; i<=googlePlayKeyLength ; i++) {
        
        key += getChar();
        
        appendDash(i,key);
    }
    
    
    return key.substr(0,key.length()-1);
}
