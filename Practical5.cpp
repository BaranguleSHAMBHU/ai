/*
Practical 5:
Elementary Chatbot using Dictionary and List
*/
/*
Sample Conversation:

===================================
 Welcome to Customer Support Bot
===================================

Type 'bye' to exit the chatbot.

You: hello
Bot: Hello! How can I help you?

You: tell me about products
Bot: We offer laptops, mobiles, and accessories.

You: what is delivery time
Bot: Delivery takes 3 to 5 working days.

You: payment methods
Bot: We accept UPI, Cards, and Net Banking.

You: bye
Bot: Thank you for visiting. Have a nice day!
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert input string to lowercase
string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main()
{
    cout << "===================================" << endl;
    cout << " Welcome to Customer Support Bot " << endl;
    cout << "===================================" << endl;

    cout << "\nType 'bye' to exit the chatbot.\n" << endl;

    // Dictionary containing chatbot keywords
    map<string, vector<string>> responses;

    responses["greeting"] = {"hi", "hello", "hey"};
    responses["products"] = {"product", "products", "items"};
    responses["price"] = {"price", "cost", "rate"};
    responses["delivery"] = {"delivery", "shipping"};
    responses["payment"] = {"payment", "upi", "card"};
    responses["contact"] = {"contact", "email", "phone"};

    // Response messages
    map<string, string> reply;

    reply["greeting"] = "Hello! How can I help you?";
    reply["products"] = "We offer laptops, mobiles, and accessories.";
    reply["price"] = "Prices vary depending on the product.";
    reply["delivery"] = "Delivery takes 3 to 5 working days.";
    reply["payment"] = "We accept UPI, Cards, and Net Banking.";
    reply["contact"] = "You can contact us at support@example.com";

    string user;

    while (true)
    {
        cout << "You: ";
        getline(cin, user);

        user = toLowerCase(user);

        // Exit condition
        if (user == "bye")
        {
            cout << "Bot: Thank you for visiting. Have a nice day!" << endl;
            break;
        }

        bool found = false;

        // Search keywords in dictionary
        for (auto item : responses)
        {
            string key = item.first;
            vector<string> keywords = item.second;

            for (string word : keywords)
            {
                if (user.find(word) != string::npos)
                {
                    cout << "Bot: " << reply[key] << endl;
                    found = true;
                    break;
                }
            }

            if (found)
            {
                break;
            }
        }

        // Default response
        if (!found)
        {
            cout << "Bot: Sorry, I did not understand your query." << endl;
        }
    }

    return 0;
}