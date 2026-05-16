''' Practical 6:-
Expert System for Hospitals and Medical Facilities '''

print("========================================")
print(" Hospital Expert System ")
print("========================================")

# Knowledge base using dictionary
disease_data = {
    "fever": {
        "disease": "Flu",
        "advice": "Take rest and drink plenty of fluids."
    },

    "cough": {
        "disease": "Cold",
        "advice": "Use cough syrup and stay hydrated."
    },

    "headache": {
        "disease": "Migraine",
        "advice": "Take proper sleep and avoid stress."
    },

    "stomach pain": {
        "disease": "Acidity",
        "advice": "Avoid oily food and drink more water."
    },

    "chest pain": {
        "disease": "Heart Problem",
        "advice": "Consult a doctor immediately."
    }
}

print("\nAvailable symptoms:")
for symptom in disease_data:
    print("-", symptom)

# User input
user_symptom = input("\nEnter your symptom: ").lower()

# Expert system logic
if user_symptom in disease_data:

    print("\nPossible Disease:",
          disease_data[user_symptom]["disease"])

    print("Medical Advice:",
          disease_data[user_symptom]["advice"])

else:
    print("\nSorry! Symptom not found in database.")
    print("Please consult a doctor.")


'''
========================================
 Hospital Expert System
========================================

Available symptoms:
- fever
- cough
- headache
- stomach pain
- chest pain

Enter your symptom: fever

Possible Disease: Flu
Medical Advice: Take rest and drink plenty of fluids.
'''
