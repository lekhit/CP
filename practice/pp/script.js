// Game State Management
const gameState = {
    currentZone: 1,
    totalXP: 0,
    level: 1,
    streak: 0,
    problemsSolved: [],
    achievements: [],
    mushrooms: 0,
    bosses: 0,
    firstAttempts: 0,
    lastPlayDate: null,
    username: '',
    soundEnabled: true
};

// Problem Database
const zones = {
    1: {
        name: "Sorting Gardens",
        requiredXP: 30,
        problems: [
            {id: '1399A', name: 'Remove Smallest', difficulty: 'Easy (800)', xp: 8, special: '', link: 'https://codeforces.com/problemset/problem/1399/A'},
            {id: '1353B', name: 'Two Arrays And Swaps', difficulty: 'Easy (800)', xp: 8, special: '', link: 'https://codeforces.com/problemset/problem/1353/B'},
            {id: '1092B', name: 'Teams Forming', difficulty: 'Easy (800)', xp: 8, special: '🍄', link: 'https://codeforces.com/problemset/problem/1092/B'}
        ]
    },
    2: {
        name: "Two Pointer Temple",
        requiredXP: 80,
        problems: [
            {id: '1367B', name: 'Even Array', difficulty: 'Easy (800)', xp: 8, special: '', link: 'https://codeforces.com/problemset/problem/1367/B'},
            {id: '1462C', name: 'Unique Number', difficulty: 'Easy (900)', xp: 9, special: '', link: 'https://codeforces.com/problemset/problem/1462/C'},
            {id: '1251A', name: 'Broken Keyboard', difficulty: 'Medium (1000)', xp: 10, special: '🍄', link: 'https://codeforces.com/problemset/problem/1251/A'},
            {id: '1343C', name: 'Alternating Subsequence', difficulty: 'Hard (1200)', xp: 12, special: '', link: 'https://codeforces.com/problemset/problem/1343/C'},
            {id: '1324D', name: 'Pair of Topics', difficulty: 'Boss (1400)', xp: 14, special: '⭐', boss: true, link: 'https://codeforces.com/problemset/problem/1324/D'}
        ]
    },
    3: {
        name: "Binary Search Fortress",
        requiredXP: 150,
        problems: [
            {id: '670D1', name: 'Magic Powder - 1', difficulty: 'Medium (1100)', xp: 11, special: '', link: 'https://codeforces.com/problemset/problem/670/D1'},
            {id: '1354B', name: 'Ternary String', difficulty: 'Medium (1200)', xp: 12, special: '', link: 'https://codeforces.com/problemset/problem/1354/B'},
            {id: '1165C', name: 'Good String', difficulty: 'Hard (1300)', xp: 13, special: '🍄', link: 'https://codeforces.com/problemset/problem/1165/C'},
            {id: '1201C', name: 'Maximum Median', difficulty: 'Hard (1400)', xp: 14, special: '', link: 'https://codeforces.com/problemset/problem/1201/C'},
            {id: '1487D', name: 'Pythagorean Triples', difficulty: 'Boss (1500)', xp: 15, special: '⭐', boss: true, link: 'https://codeforces.com/problemset/problem/1487/D'},
            {id: '1288C', name: 'Two Arrays', difficulty: 'Elite (1600)', xp: 16, special: '👑', link: 'https://codeforces.com/problemset/problem/1288/C'}
        ]
    },
    4: {
        name: "Interval Islands",
        requiredXP: 200,
        problems: [
            {id: '978C', name: 'Letters', difficulty: 'Easy (1000)', xp: 10, special: '', link: 'https://codeforces.com/problemset/problem/978/C'},
            {id: '1399C', name: 'Boats Competition', difficulty: 'Medium (1200)', xp: 12, special: '🍄', link: 'https://codeforces.com/problemset/problem/1399/C'},
            {id: '1369C', name: 'RationalLee', difficulty: 'Hard (1400)', xp: 14, special: '', link: 'https://codeforces.com/problemset/problem/1369/C'},
            {id: '1358C', name: 'Celex Update', difficulty: 'Elite (1600)', xp: 16, special: '⭐', link: 'https://codeforces.com/problemset/problem/1358/C'}
        ]
    },
    5: {
        name: "Grand Synthesis",
        requiredXP: 300,
        problems: [
            {id: '1341B', name: 'Nastya and Door', difficulty: 'Medium (1300)', xp: 13, special: '', link: 'https://codeforces.com/problemset/problem/1341/B'},
            {id: '1350B', name: 'Orac and Models', difficulty: 'Hard (1400)', xp: 14, special: '🍄', link: 'https://codeforces.com/problemset/problem/1350/B'},
            {id: '1195C', name: 'Basketball Exercise', difficulty: 'Hard (1400)', xp: 14, special: '⭐', link: 'https://codeforces.com/problemset/problem/1195/C'},
            {id: '1473D', name: 'Program', difficulty: 'Legendary (1700)', xp: 17, special: '', link: 'https://codeforces.com/problemset/problem/1473/D'},
            {id: '1370D', name: 'Odd-Even Subsequence', difficulty: 'Legendary (1700)', xp: 17, special: '🍄', link: 'https://codeforces.com/problemset/problem/1370/D'},
            {id: '1486D', name: 'Max Median', difficulty: 'Mythic (1900)', xp: 19, special: '', link: 'https://codeforces.com/problemset/problem/1486/D'},
            {id: '1551D2', name: 'Domino (hard)', difficulty: 'Final Boss (1900)', xp: 19, special: '👑', boss: true, link: 'https://codeforces.com/problemset/problem/1551/D2'}
        ]
    }
};

// Daily Challenges
const dailyChallenges = [
    {name: "Speed Run", desc: "Solve in < 30 min", xp: 20},
    {name: "No Compile Errors", desc: "First compile success", xp: 15},
    {name: "Helper", desc: "Explain to someone", xp: 10},
    {name: "Researcher", desc: "Read editorial", xp: 10},
    {name: "Time Traveler", desc: "Solve old problem", xp: 15},
    {name: "Lucky Day", desc: "Free bonus!", xp: 25}
];

// Initialize Game
function initGame() {
    loadProgress();
    updateDisplay();
    renderZone(1);
    checkStreak();
}

// Save/Load Progress
function saveProgress() {
    localStorage.setItem('cfQuestState', JSON.stringify(gameState));
}

function loadProgress() {
    const saved = localStorage.getItem('cfQuestState');
    if (saved) {
        Object.assign(gameState, JSON.parse(saved));
    }
}

// Zone Selection
function selectZone(zoneNum) {
    const zoneBtn = document.getElementById(`zone-${zoneNum}`);
    if (zoneBtn.classList.contains('locked')) {
        showNotification('🔒 Zone Locked!', 'Complete previous zones first.');
        return;
    }
    
    document.querySelectorAll('.zone-tab').forEach(tab => tab.classList.remove('active'));
    zoneBtn.classList.add('active');
    gameState.currentZone = zoneNum;
    renderZone(zoneNum);
    
    if (gameState.soundEnabled) playSound('click');
}

// Render Zone Problems
function renderZone(zoneNum) {
    const zone = zones[zoneNum];
    const questArea = document.getElementById('quest-area');
    questArea.innerHTML = '';
    
    zone.problems.forEach(problem => {
        const isCompleted = gameState.problemsSolved.includes(problem.id);
        const questCard = document.createElement('div');
        questCard.className = `quest-card ${isCompleted ? 'completed' : ''} ${problem.boss ? 'boss' : ''}`;
        
        questCard.innerHTML = `
            <div class="quest-header">
                <span class="quest-name">${problem.name}</span>
                <span class="quest-xp">+${problem.xp} XP</span>
            </div>
            <div class="quest-difficulty">${problem.difficulty}</div>
            ${problem.special ? `<span class="quest-special">${problem.special}</span>` : ''}
            <a href="${problem.link}" target="_blank" class="quest-link">Solve Problem</a>
            ${!isCompleted ? `<button class="complete-btn" onclick="completeProblem('${problem.id}', ${problem.xp}, '${problem.special}', ${problem.boss || false})">Mark Complete</button>` : '<span style="color: green;">✓ Completed</span>'}
        `;
        
        questArea.appendChild(questCard);
    });
}

// Complete Problem
function completeProblem(problemId, xp, special, isBoss) {
    if (gameState.problemsSolved.includes(problemId)) return;
    
    // Add to solved
    gameState.problemsSolved.push(problemId);
    
    // Calculate XP (double for first attempt)
    const isFirstAttempt = confirm('Did you solve this on your first attempt?');
    let earnedXP = xp;
    if (isFirstAttempt) {
        earnedXP *= 2;
        gameState.firstAttempts++;
        showAchievement('🔥 First Try!', `Double XP! +${earnedXP} XP`);
    }
    
    // Add special bonuses
    if (special === '🍄') {
        earnedXP += 30;
        gameState.mushrooms++;
        showAchievement('🍄 Mushroom Found!', '+30 Bonus XP!');
    }
    if (special === '⭐') {
        unlockSecretBadge(problemId);
    }
    if (isBoss) {
        gameState.bosses++;
        showAchievement('👑 Boss Defeated!', 'Legendary victory!');
    }
    
    // Update XP and level
    gameState.totalXP += earnedXP;
    checkLevelUp();
    
    // Check zone completion
    checkZoneCompletion();
    
    // Update display
    updateDisplay();
    renderZone(gameState.currentZone);
    saveProgress();
    
    if (gameState.soundEnabled) playSound('success');
}

// Level System
function checkLevelUp() {
    const xpThresholds = [30, 80, 150, 200, 300, 400, 500, 650, 800, 1000];
    let newLevel = 1;
    
    for (let i = 0; i < xpThresholds.length; i++) {
        if (gameState.totalXP >= xpThresholds[i]) {
            newLevel = i + 2;
        } else {
            break;
        }
    }
    
    if (newLevel > gameState.level) {
        gameState.level = newLevel;
        showAchievement('🎉 Level Up!', `You reached Level ${gameState.level}!`);
    }
}

// Zone Completion Check
function checkZoneCompletion() {
    const currentZoneProblems = zones[gameState.currentZone].problems;
    const zoneComplete = currentZoneProblems.every(p => gameState.problemsSolved.includes(p.id));
    
    if (zoneComplete && gameState.currentZone < 5) {
        const nextZone = gameState.currentZone + 1;
        document.getElementById(`zone-${nextZone}`).classList.remove('locked');
        showAchievement('🏆 Zone Complete!', `Zone ${nextZone} Unlocked!`);
        
        // Auto advance to next zone
        setTimeout(() => selectZone(nextZone), 2000);
    }
}

// Daily Challenge
function spinDailyChallenge() {
    const wheel = document.querySelector('.spin-wheel');
    const result = document.getElementById('daily-result');
    
    wheel.classList.add('spinning');
    
    setTimeout(() => {
        wheel.classList.remove('spinning');
        const challenge = dailyChallenges[Math.floor(Math.random() * dailyChallenges.length)];
        
        result.innerHTML = `
            <strong>${challenge.name}</strong><br>
            ${challenge.desc}<br>
            Reward: +${challenge.xp} XP
        `;
        result.classList.remove('hidden');
        
        // Add XP if they complete it
        if (confirm('Did you complete this challenge?')) {
            gameState.totalXP += challenge.xp;
            updateDisplay();
            saveProgress();
            showAchievement('🎲 Challenge Complete!', `+${challenge.xp} XP!`);
        }
    }, 1000);
}

// Streak System
function checkStreak() {
    const today = new Date().toDateString();
    const lastPlay = gameState.lastPlayDate;
    
    if (lastPlay) {
        const yesterday = new Date(Date.now() - 86400000).toDateString();
        if (lastPlay === yesterday) {
            gameState.streak++;
            if (gameState.streak >= 3) {
                gameState.totalXP += 50;
                showAchievement('🔥 Streak Bonus!', '3+ day streak! +50 XP');
            }
        } else if (lastPlay !== today) {
            gameState.streak = 1;
        }
    } else {
        gameState.streak = 1;
    }
    
    gameState.lastPlayDate = today;
    saveProgress();
}

// Display Updates
function updateDisplay() {
    // Update XP Bar
    const xpForNextLevel = [30, 80, 150, 200, 300, 400, 500, 650, 800, 1000][gameState.level - 1] || 1000;
    const xpProgress = (gameState.totalXP / xpForNextLevel) * 100;
    
    document.getElementById('xp-fill').style.width = `${Math.min(xpProgress, 100)}%`;
    document.getElementById('current-xp').textContent = gameState.totalXP;
    document.getElementById('next-level-xp').textContent = xpForNextLevel;
    document.getElementById('player-level').textContent = gameState.level;
    
    // Update Stats
    document.getElementById('problems-solved').textContent = gameState.problemsSolved.length;
    document.getElementById('total-xp').textContent = gameState.totalXP;
    document.getElementById('mushrooms').textContent = gameState.mushrooms;
    document.getElementById('bosses').textContent = gameState.bosses;
    document.getElementById('first-attempts').textContent = gameState.firstAttempts;
    document.getElementById('streak').textContent = gameState.streak;
    
    // Update Zone Progress
    for (let i = 1; i <= 5; i++) {
        const zoneProblems = zones[i].problems;
        const solved = zoneProblems.filter(p => gameState.problemsSolved.includes(p.id)).length;
        const progressText = document.getElementById(`zone-${i}-progress`);
        
        if (i === 1 || !document.getElementById(`zone-${i}`).classList.contains('locked')) {
            progressText.textContent = `${solved}/${zoneProblems.length}`;
        }
    }
    
    // Update Badges
    updateBadges();
}

// Badge System
function updateBadges() {
    const badges = document.querySelectorAll('.badge');
    
    // Zone completion badges
    for (let i = 1; i <= 5; i++) {
        const zoneComplete = zones[i].problems.every(p => gameState.problemsSolved.includes(p.id));
        if (zoneComplete) {
            badges[i - 1].classList.remove('locked');
            badges[i - 1].classList.add('unlocked');
        }
    }
    
    // Special badges
    if (gameState.firstAttempts >= 5) {
        badges.classList.remove('locked');
        badges.classList.add('unlocked');
    }
}

// Achievement Notifications
function showAchievement(title, description) {
    const popup = document.getElementById('achievement-popup');
    document.getElementById('achievement-title').textContent = title;
    document.getElementById('achievement-desc').textContent = description;
    
    popup.classList.remove('hidden');
    
    setTimeout(() => {
        popup.classList.add('hidden');
    }, 3000);
}

function showNotification(title, message) {
    alert(`${title}\n${message}`);
}

// Secret Badge Unlocks
function unlockSecretBadge(problemId) {
    const badges = {
        '1324D': 'Combo Master',
        '1487D': 'Math Wizard',
        '1358C': 'Range Master',
        '1195C': 'Athletic Coder'
    };
    
    if (badges[problemId]) {
        showAchievement('🌟 Secret Badge!', `${badges[problemId]} unlocked!`);
    }
}

// Sound Effects (placeholder)
function playSound(type) {
    // Add sound effects here if desired
    console.log(`Playing sound: ${type}`);
}

function toggleSound() {
    gameState.soundEnabled = !gameState.soundEnabled;
    document.querySelector('.sound-toggle').textContent = gameState.soundEnabled ? '🔊' : '🔇';
    saveProgress();
}

// Reset Progress
function confirmReset() {
    if (confirm('Are you sure you want to reset all progress? This cannot be undone!')) {
        localStorage.removeItem('cfQuestState');
        location.reload();
    }
}

// Initialize on load
window.onload = initGame;