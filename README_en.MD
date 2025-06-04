[English](README_en.MD) | [中文](README.MD)
# Project Introduction
This is the final major assignment for the second semester of the first year of SDU-2025, requiring the development of a desktop tool. For more details, see the project requirements: [C++ Project Requirements](https://github.com/YanniYang-PolyU/2025-Cplusplus-Project), and it includes three modules:
1. Finance Note
2. Reminder (Course Reminder)
3. Password Manager
# Deployment
> Note: This project is now completed!
> 
This project uses `C++` and `Qt` to achieve cross-platform development. If you want to clone the project locally and compile it, please ensure you follow these steps:
1. Install the necessary toolchain: `cmake3.31.0+`, download the `Qt6` library (recommended version `Qt6.7.3`) and corresponding compiler (usually selectable in the Qt online installer).
2. Add the above tools to the environment variables
    - If on `Windows`, add the path where `cmake.exe` is located to `PATH`, add `{drive}:\path\to\qt\{version}\{compiler_type}\lib\cmake\Qt6` (this is just an example, remember it should be an absolute path) to the `Qt6_DIR` variable, and add the path to the Qt toolchain to the `PATH` (preferably at the top).
    - If on `Linux`, follow the same steps, except that the `cmake` suffix does not have `.exe`, and paths should use `/` as separators.
> Once the project is completed, a release version of the executable will be provided, and users can simply download and decompress it to use.
# Main Features of the Project
> Opening the program directly will pop up a graphical interface; opening it from the command line with any command-line arguments will open the command-line interface, e.g., `./SDU_2_homework 1`
## Finance Note
### Original Requirements
- Record daily expenses: date (`YYYY-MM-DD`), amount, category
- Monthly expense statistics: input month (`YYYY-MM`), display all expense records for that month and total amount
- Data saving: save records to the `finance.txt` file
- Data display: tabular output of expense records (aligned column widths)
### Expanded Functions
- Sort expense records by date
- Sort expense records by amount (not yet completed)
- Query expense records by category (not yet completed)
## Course Reminder
### Original Requirements
- Add reminders: include time (`YYYY-MM-DD HH:MM`), event content, priority (1-3)
- Query by date: input specified date (`YYYY-MM-DD`) to show all reminders for that day
- Automatic sorting: automatically sort reminders in chronological order
- Data saving: save records to the `reminder.txt` file
### Expanded Functions
- Add a recycle bin, overdue items can be moved to the recycle bin and viewed there
## Password Manager
### Original Requirements
- Store passwords: record website name, username, password (stored encrypted)
- Password query: support case-insensitive search by website name, display plaintext password
- Data saving: save records to the `password.txt` file
### Expanded Functions
- The password encryption credentials are created by the user and cannot be cracked through hard-coded programs
- When verifying user credentials, use the `SHA256` algorithm to encrypt credentials, increasing the difficulty of dictionary attacks
- Support fuzzy search when searching websites
- Add `salt` for credential verification, adjust credential data based on `salt` before encryption, further increasing the difficulty of dictionary attacks (not yet completed)
## File Operations
### Original Requirements
- Automatically store records in the corresponding files when adding records (e.g., finance information stored in `finance.txt`, course reminders in `reminder.txt`, passwords in `password.txt`)
- Automatically load all records from the files when the system starts
### Expanded Functions
- Store the files again upon closing
- Automatically initialize files
- Add a logging system
> Graphical functions remain consistent after GUI implementation