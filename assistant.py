"""Neuro - the NeuroOS assistant (simple intent matching, no libraries needed).
Run:  python3 assistant.py
"""

INTENTS = {
    "cpu":      (["cpu", "slow", "speed"],      "CPU load is 23%. Background tasks set to low priority."),
    "memory":   (["memory", "ram"],             "Memory: 412 MB used of 2048 MB."),
    "files":    (["file", "find", "open"],      "Found 4 files in /home."),
    "security": (["virus", "secure", "safe"],   "Security scan finished. 0 threats found."),
    "greeting": (["hello", "hi", "hey"],        "Hello! I am Neuro."),
}

def understand(text):
    """Return the best matching intent for the user's text."""
    words = text.lower().split()
    best, best_hits = None, 0
    for name, (keywords, _) in INTENTS.items():
        hits = sum(1 for k in keywords if any(k in w for w in words))
        if hits > best_hits:
            best, best_hits = name, hits
    return best

def reply(text):
    intent = understand(text)
    return INTENTS[intent][1] if intent else "I am still learning. Ask about cpu, memory, files or security."

if __name__ == "__main__":
    print("Neuro assistant. Type 'exit' to quit.")
    while True:
        q = input("you> ")
        if q.strip().lower() == "exit":
            break
        print("neuro>", reply(q))
