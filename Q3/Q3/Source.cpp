/*********************************************************************************
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
********************************************************************************/

// alright, we have to first get the prime numbers
// then we have to sort them largest to smallest?
#include <iostream>

class Node {
public:
	int num;
	Node* pNext = NULL;
};

class LinkedList {
public:
	Node* pHead = NULL;

	void Add(int num) {
		if (pHead == NULL) {
			pHead = new Node();
			pHead->num = num;
			return;
		}
		
		Node* pTemp = pHead;
		while (pTemp->pNext != NULL) {
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = new Node();
		pTemp->pNext->num = num;
	}

	bool Contains(int num) {
		if (pHead == NULL)
			return false;

		Node* pTemp = pHead;
		while (true) {
			if (pTemp->num == num) {
				return true;
			}

			if (pTemp->pNext == NULL) {
				return false;
			}

			pTemp = pTemp->pNext;
		}
	}

	int Largest() {
		if (pHead == NULL) {
			return 0;
		}

		int largest = pHead->num;
		Node* pTemp = pHead;
		while (pTemp->pNext != NULL) {
			pTemp = pTemp->pNext;
			if (pTemp->num > largest) {
				largest = pTemp->num;
			}
		}

		return largest;
	}

	int Length() {
		if (pHead == NULL)
			return 0;

		int num = 1;
		Node* pTemp = pHead;
		while (pTemp->pNext != NULL) {
			num++;
			pTemp = pTemp->pNext;
		}

		return num;
	}
};



bool IsPrime(int num) 
{
	// handling irritating low numbers
	if (num <= 3 && num > 0) return true;

	for (int i = 2; i < num; i++) {
		if (num%i == 0) return false;
	}

	return true;
}

int main()
{
	//long long 			num = 13195;
	long long 			num = 600851475143;
	long long 			runNum = num;
	int			mInd = 0;
	//int*		mPrimes = new int[32];
	LinkedList*	mPrimes = new LinkedList();


	for (long long i = 2; i < runNum+1; i++) {
		if (!IsPrime(i)) continue;

		while (runNum % i == 0) {
			runNum /= i;
			if(!mPrimes->Contains(i))
				mPrimes->Add(i);
			std::cout << "\nPrime Found: " << i;
			std::cout << "\nNum remaining: " << runNum;
		}
	}

	Node* pTemp = mPrimes->pHead;
	int mult = pTemp->num;
	while (pTemp->pNext != NULL) {
		mult *= pTemp->pNext->num;
		pTemp = pTemp->pNext;
	}

	std::cout << "\nProduct of Primes: " << mult;
	std::cout << "\nLargest: " << mPrimes->Largest();

	std::getchar();
	return 0;
}