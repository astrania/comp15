#include <iostream>
#include <cstdlib>
#include <time.h>
#include "hand.h"

using namespace std;

void test_insert_at_back() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs

        test_list.print_list(); // should be blank
        cout<<test_list.cards_in_hand()<<endl;//should print 0

        test_list.insert_at_back(card1); // insert a card
        cout<<test_list.cards_in_hand()<<endl;//should print 1
        test_list.print_list(); // should print the Ace of Diamonds (AD)

        test_list.insert_at_back(card2); // insert another card
        cout<<test_list.cards_in_hand()<<endl;//should print 2
        test_list.print_list(); // should print AD,5S

        test_list.insert_at_back(card3); // insert another card
        cout<<test_list.cards_in_hand()<<endl;//should print 3
        test_list.print_list(); // should print AD,5S,8C
}

void test_insert_at_front() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        test_list.print_list(); // should be blank
        cout<<test_list.cards_in_hand()<<endl;

        test_list.insert_at_front(card1); // insert a card
        cout<<test_list.cards_in_hand()<<endl;
        test_list.print_list(); // should print the Ace of Diamonds (AD)

        test_list.insert_at_front(card2); // insert another card
        cout<<test_list.cards_in_hand()<<endl;
        test_list.print_list(); // should print 5S,AD

        test_list.insert_at_front(card3); // insert another card
        cout<<test_list.cards_in_hand()<<endl;
        test_list.print_list(); // should print 8C,5S,AD
}

void test_insert_at_index() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');

        test_list.insert_at_index(card1,0); // insert a card
        test_list.print_list();

        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
        test_list.print_list(); // should print 8C,5S,AD
	  
        test_list.insert_at_index(card4,4);
        test_list.print_list(); // should print 8C,6S,5S,AD
}

void test_replace_at_index() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
        test_list.print_list(); // should print 8C,5S,AD

        test_list.replace_at_index(card4,1);
        test_list.print_list(); // should print 8C,6S,AD
}

void test_card_at() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
        test_list.print_list(); // should print 8C,5S,AD

        test_list.card_at(0).print_card(); // should print 8C
        test_list.card_at(1).print_card(); // should print 5S
        test_list.card_at(2).print_card(); // should print AD
}

void test_has_card() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');

        cout << test_list.has_card(card4);// should print false
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
        test_list.print_list(); // should print 8C,5S,AD
        cout << test_list.has_card(card4)<<endl;// should print false
        cout << test_list.has_card(card1)<<endl;// should print true
        cout << test_list.has_card(card2)<<endl;// should print true
        cout << test_list.has_card(card3)<<endl;// should print true

}

void test_remove() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
	
        test_list.print_list(); // should print 8C,5S,AD

        cout<< test_list.remove(card4) <<endl;// should print false
        test_list.print_list(); //should print 8C,5S,AD

        cout<< test_list.remove(card1) <<endl;// should print true
        test_list.print_list(); // should print 8C,5S

        cout<< test_list.remove(card3) <<endl;// should print true
        test_list.print_list(); // should print 5S

        cout<< test_list.remove(card2) <<endl;// should print true
        test_list.print_list(); // should print nothing
}

void test_remove_from_front() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
	
        test_list.print_list(); // should print 8C,5S,AD

        test_list.remove_from_front().print_card();// should print 8C
        cout<<endl;
        test_list.print_list(); // should print 5S,AD

        test_list.remove_from_front().print_card();// should print 5S
        cout<<endl;
        test_list.print_list(); // should print AD

        test_list.remove_from_front().print_card();// should print AD
        cout<<endl;
        test_list.print_list(); // should print nothing
}

void test_remove_from_back() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
        test_list.print_list(); // should print 8C,5S,AD

        test_list.remove_from_back().print_card();// should print AD
        cout<<endl;
        test_list.print_list(); // should print 8C,5S

        test_list.remove_from_back().print_card();// should print 5S
        cout<<endl;
        test_list.print_list(); // should print 8C

        test_list.remove_from_back().print_card();// should print 8C
        cout<<endl;
        test_list.print_list(); // should print nothing
}

void test_remove_from_index() {
        List_linked_list test_list;
        Card card1('A','D'); // ace of diamonds
        Card card2('5','S'); // five of spades
        Card card3('8','C'); // eight of clubs
        Card card4('6','S');
        test_list.insert_at_front(card1); // insert a card
        test_list.insert_at_front(card2); // insert another card
        test_list.insert_at_front(card3); // insert another card
        test_list.print_list(); // should print 8C,5S,AD
	
	
        test_list.remove_from_index(2).print_card();// should print AD
        cout<<endl;
        test_list.print_list(); // should print 8C,5S

        test_list.remove_from_index(1).print_card();// should print 5S
        cout<<endl;
        test_list.print_list(); // should print 8C

        test_list.remove_from_index(0).print_card();// should print 8C
        cout<<endl;
        test_list.print_list(); // should print nothing
}

int main(int argc, char **argv)
{
	Hand deck, deck2, hand1, hand2;
	
	
	deck.create_deck();
	deck.read_deck();
	deck.print_hand();

	Card c('3', 'H');

	deck.remove_card(c);

	deck.shuffle();
	deck.print_hand_int();
		
	for (int i = 0; i < 5; i++) {
		deck.deal_card_from_top(hand1);
		deck.deal_card_from_top(hand2);
	}

	hand1.order_hand_by_suit();
	hand2.order_hand_by_suit();
	
	deck.print_hand();
	hand1.print_hand();
	hand2.print_hand();
	
	// test functions
	//test_insert_at_back();
	//test_insert_at_front();
	//test_insert_at_index();
	
	//test_replace_at_index();
	//test_card_at();
	//test_has_card();
	
	test_remove();
	//test_remove_from_front();
	//test_remove_from_back();
	//test_remove_from_index();

	return 0;
}