"""Learns which app you open most and predicts the next one.
Run: python3 usage_predictor.py
"""
from collections import Counter, defaultdict

class UsagePredictor:
    def __init__(self):
        self.after = defaultdict(Counter)   # app -> counts of what came next
        self.last = None

    def record(self, app):
        if self.last:
            self.after[self.last][app] += 1
        self.last = app

    def predict(self, app):
        counts = self.after.get(app)
        return counts.most_common(1)[0][0] if counts else None

if __name__ == "__main__":
    p = UsagePredictor()
    for app in ["browser", "notes", "browser", "notes", "browser", "music", "browser", "notes"]:
        p.record(app)
    print("After 'browser' you usually open:", p.predict("browser"))
