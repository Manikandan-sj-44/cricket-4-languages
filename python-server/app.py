# python-server/app.py
from flask import Flask, render_template_string
import datetime

app = Flask(__name__)

HTML_TEMPLATE = """
<!DOCTYPE html>
<html>
<head>
    <title>🏏 Cricket Scores - Python</title>
    <style>
        * { margin: 0; padding: 0; box-sizing: border-box; }
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #1a472a 0%, #0e2a1a 100%);
            min-height: 100vh;
            padding: 20px;
        }
        .container { max-width: 1200px; margin: 0 auto; }
        h1 { text-align: center; color: #ffd700; margin-bottom: 20px; font-size: 3em; }
        .lang-badge {
            text-align: center;
            background: #ffd700;
            color: #1a472a;
            display: inline-block;
            padding: 5px 20px;
            border-radius: 20px;
            margin-bottom: 20px;
            font-weight: bold;
        }
        .matches-grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(350px, 1fr)); gap: 20px; }
        .match-card {
            background: white;
            border-radius: 15px;
            padding: 20px;
            box-shadow: 0 10px 20px rgba(0,0,0,0.2);
        }
        .teams { display: flex; justify-content: space-between; align-items: center; margin-bottom: 15px; }
        .team { text-align: center; flex: 1; }
        .team-name { font-size: 1.3em; color: #1a472a; font-weight: bold; }
        .team-score { font-size: 1.5em; font-weight: bold; color: #333; }
        .vs { font-size: 1.2em; color: #ff6600; padding: 0 15px; }
        .status { background: #ffd700; padding: 8px; border-radius: 8px; text-align: center; font-weight: bold; }
        .result { background: #1a472a; color: #ffd700; padding: 8px; border-radius: 8px; text-align: center; font-weight: bold; }
        .overs { text-align: center; color: #666; margin-top: 10px; }
        .footer { text-align: center; color: #ccc; margin-top: 30px; padding: 20px; }
        .time { font-size: 0.8em; margin-top: 10px; }
    </style>
</head>
<body>
    <div class="container">
        <div style="text-align: center;">
            <div class="lang-badge">🐍 PYTHON FLASK SERVER</div>
        </div>
        <h1>🏏 LIVE CRICKET SCORES</h1>
        <div class="matches-grid">
            {% for match in matches %}
            <div class="match-card">
                <div class="teams">
                    <div class="team">
                        <div class="team-name">{{ match.team1 }}</div>
                        <div class="team-score">{{ match.score1 }}</div>
                    </div>
                    <div class="vs">VS</div>
                    <div class="team">
                        <div class="team-name">{{ match.team2 }}</div>
                        <div class="team-score">{{ match.score2 }}</div>
                    </div>
                </div>
                <div class="details">
                    {% if match.result %}
                        <div class="result">🏆 {{ match.result }}</div>
                    {% else %}
                        <div class="status">⚡ {{ match.status }}</div>
                    {% endif %}
                    <div class="overs">Overs: {{ match.overs }}</div>
                </div>
            </div>
            {% endfor %}
        </div>
        <div class="footer">
            <p>Language: <strong>Python</strong> | Framework: Flask | Internal Port: 9001</p>
            <p>Accessed via: <strong>/python</strong> path on proxy</p>
            <div class="time">{{ timestamp }}</div>
        </div>
    </div>
</body>
</html>
"""

matches = [
    {"id": 1, "team1": "India", "team2": "Australia", "score1": "245/3", "score2": "210/5", 
     "overs": "35.2", "status": "India needs 35 runs in 88 balls", "result": ""},
    {"id": 2, "team1": "England", "team2": "South Africa", "score1": "189/7", "score2": "156/4", 
     "overs": "28.1", "status": "England leads by 33 runs", "result": ""},
    {"id": 3, "team1": "Pakistan", "team2": "New Zealand", "score1": "312/4", "score2": "278/6", 
     "overs": "50.0", "status": "", "result": "Pakistan won by 34 runs"},
    {"id": 4, "team1": "Sri Lanka", "team2": "Bangladesh", "score1": "168/2", "score2": "145/3", 
     "overs": "32.4", "status": "Sri Lanka needs 23 runs", "result": ""}
]

@app.route('/')
def home():
    return render_template_string(HTML_TEMPLATE, 
                                  matches=matches,
                                  timestamp=datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

@app.route('/health')
def health():
    return "OK", 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=9001, debug=False)
