/*
 * Checkout.h
 *
 *  Created on: 30 Jul 2022
 *      Author: david
 */

#ifndef SRC_CHECKOUT_H_
#define SRC_CHECKOUT_H_

#include <string>
#include <map>

class Checkout {
public:
	Checkout();
	virtual ~Checkout();

	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	void addDiscount(std::string item, int nbrOfItems, int discountPrice);
	int calculateTotal();

protected:
	struct Discount{
		int nbrOfItems;
		int discountPrice;
	};
	std::map<std::string, int> prices;
	std::map<std::string, int> items;
	std::map<std::string, Discount> discounts;

	int total;

	void calculateItem(std::string item, int itemCnt);
	void calculateDiscount(std::string item, int itemCnt, Discount discount);
};

#endif /* SRC_CHECKOUT_H_ */
