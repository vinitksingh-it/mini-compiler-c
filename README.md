🚀 Mini Compiler in C

A fully functional Mini Compiler built in C that demonstrates core concepts of compiler design including lexical analysis, parsing, intermediate code generation, optimization, and error handling.

⸻

🔥 Features
	•	🔍 Lexical Analysis (Tokenization)
	•	🌳 Recursive Descent Parsing
	•	🌲 Abstract Syntax Tree (AST)
	•	📒 Symbol Table Management
	•	⚙️ Three Address Code Generation
	•	🚀 Constant Folding Optimization
	•	❌ Syntax Error Detection

⸻

🧠 Compiler Pipeline

Input → Tokens → AST → Intermediate Code → Optimized Output

🧪 Example Runs

Valid Input

  a = 2 + 3 * 4

Output

  a = 14

❌ Invalid Input

a = + b

Output

  Error: Invalid factor

⚙️ How to Run

 gcc *.c -o compiler
./compiler

📂 Project Structure

mini-compiler-c/
│
├── lexer.c / lexer.h     → Tokenization
├── parser.c / parser.h   → Syntax Analysis
├── codegen.c / codegen.h → Code Generation & Optimization
├── main.c                → Driver Program

💼 Skills Demonstrated
	•	Data Structures (Trees)
	•	Compiler Design Concepts
	•	C Programming
	•	Problem Solving
	•	System-Level Thinking

⸻

🚀 Future Improvements
	•	Type Checking
	•	Semantic Analysis
	•	Assembly / Machine Code Generation

⸻

👨‍💻 Author

Vinit Kumar Singh
GitHub: https://github.com/vinitksingh-it
