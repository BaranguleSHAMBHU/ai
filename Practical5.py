''' Practical 5:-
Elementary Chatbot using Dictionary and List '''

print("===================================")
print(" Welcome to Customer Support Bot ")
print("===================================")

print("\nType 'bye' to exit the chatbot.\n")

# Dictionary containing chatbot responses
responses = {
    "greeting": ["hi", "hello", "hey"],
    "products": ["product", "products", "items"],
    "price": ["price", "cost", "rate"],
    "delivery": ["delivery", "shipping"],
    "payment": ["payment", "upi", "card"],
    "contact": ["contact", "email", "phone"]
}

# Response messages
reply = {
    "greeting": "Hello! How can I help you?",
    "products": "We offer laptops, mobiles, and accessories.",
    "price": "Prices vary depending on the product.",
    "delivery": "Delivery takes 3 to 5 working days.",
    "payment": "We accept UPI, Cards, and Net Banking.",
    "contact": "You can contact us at support@example.com"
}

while True:

    user = input("You: ").lower()

    # Exit condition
    if user == "bye":
        print("Bot: Thank you for visiting. Have a nice day!")
        break

    found = False

    # Search keywords in dictionary
    for key, keywords in responses.items():

        for word in keywords:

            if word in user:
                print("Bot:", reply[key])
                found = True
                break

        if found:
            break

    # Default response
    if not found:
        print("Bot: Sorry, I did not understand your query.")


'''
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
'''
