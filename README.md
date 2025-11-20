Overview
The Smart Course Counselling System is a role-based web application designed to assist students and administrators with course management, selection, and recommendation. It features distinct interfaces and capabilities for Admins and Students, enabling efficient course counselling and academic planning.

Features
Role-based Access: Separate views and features for Admin and Student users.

Admin Features:

Manage courses (add, delete, view detailed info).

Manage enrolled students and monitor course selection.

Establish and manage course prerequisites.

View analytics such as popular courses and enrollment statistics.

Student Features:

Profile setup and management.

Browse, search, and filter available courses.

Select and drop courses with real-time validation.

Receive course recommendations based on current selections and prerequisites.

Technology Stack
Frontend: HTML5, CSS3 (responsive design), vanilla JavaScript for interactions and state management.

Backend: Node.js with Express.js, serving static files and preparing for backend integrations.

Data Storage: Browser localStorage and sessionStorage for persistence during sessions.

Installation and Setup
Prerequisite: Ensure Node.js is installed.

Clone or download the project files.

Open a terminal in the project directory.

Run npm install to install the dependencies.

Start the server with npm start.

Open your browser and navigate to http://localhost:3000.

Usage
On the login page, select your role: Admin or Student.

Admins can add/remove courses, manage students, set prerequisites, and view analytics.

Students can set up their profile, browse and select courses, view recommendations, and search courses.

Troubleshooting
If port 3000 is in use, edit server.js and change the port number.

Ensure no other programs are using the same port.

Clear browser cache if styling or scripts do not load correctly.

For common errors, check the browser console (F12) and terminal logs.

Contribution
Contributions are welcome. Feel free to submit pull requests or raise issues for bugs and feature requests.
