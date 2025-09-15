#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary,  char destination) {
    // BASE CASE
   
    if (n == 1) {
        std::cout << "Move disk 1 from slot  " << source << " to slot " << destination << std::endl;
        return;
    }

    // breaking the problem into 3  parts.
    
    // Step 1:Move the top n-1 disks from the source to the auxiliary slot.
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2:Move the single largest disk (disk n) from the source to the destination slot.
  
    std::cout << "Move disk " << n << " from slot " << source << " to slot " << destination << std::endl;

    // Step 3:Move the n-1 disks from the auxiliary slot to the destination slot.
    
    towerOfHanoi(n - 1, auxiliary ,source, destination);
}

int main() {
    int numberOfDisks;

   
    std::cout << "Enter the number of disks for the Tower of Hanoi puzzle: ";
    std::cin >> numberOfDisks;

    // checking  positive number of disks.
    if (numberOfDisks <= 0) {
        std::cout << "Please enter a positive number of disks." << std::endl;
        return 1; // Exit with an error code.
    }
    
    // Call the recursive function to solve the puzzle.
    std::cout << "\nSteps to solve the Tower of Hanoi with " << numberOfDisks << " disks:" << std::endl;
    towerOfHanoi(numberOfDisks, 'A', 'B', 'C');
    
    

    int totalsteps = (1 << numberOfDisks) - 1; // 2^n - 1
    std::cout << "\nTotal steps required to solve the Tower of Hanoi with " << numberOfDisks << " disks: " << totalsteps << std::endl;
    std::cout << "\nPuzzle solved!" << std::endl;

    return 0;
}
