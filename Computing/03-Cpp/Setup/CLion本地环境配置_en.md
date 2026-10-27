# Local C++ setup: CLion (Windows / macOS)

Each student applies for JetBrains Student Pack with their own university email, then activates CLion with the JetBrains Account that receives the license. Setup is complete when a Hello World program runs locally.

## 1. Apply with your university email

### Step 1: prepare your university email

Make sure you can sign into your university mailbox and receive messages. Enter the complete email address in the application, not just your student number. You will need the mailbox for verification and license notifications.

### Step 2: open Student Pack and select Apply

Open the [JetBrains Student Pack application page](https://www.jetbrains.com/academy/student-pack/) and click Apply or Apply now to begin.

If the page first requests a JetBrains Account login, sign into an existing account or register as instructed, preferably with your university email. Then continue the student application. Creating an account alone does not grant a student license.

### Step 3: complete the student application

Follow the page instructions, select student status, use your university email for the application or eligibility verification, and provide the requested name, institution, and other details accurately. Check the email spelling before submitting. Supply any additional enrollment information requested by the page.

### Step 4: follow the university-email messages

Open your university mailbox after submitting. Find the JetBrains verification email and follow its confirmation link. If no message appears, check spam and confirm the address entered in the application.

Continue according to the email and page instructions. If the application remains under review after email verification, wait for the decision. A submitted application is not yet an active license.

### Step 5: confirm the license is linked to your account

After approval or activation instructions arrive, follow the email link and sign into [JetBrains Account](https://account.jetbrains.com/) to complete license association. Confirm that the account has a student education license usable for CLion.

Remember this account: use the same one in CLion. If you applied through an existing account, the license may belong to that account; do not switch accounts when activating the IDE.

## 2. Download and install CLion

Open the [official CLion download page](https://www.jetbrains.com/clion/download/) and select the installer for your computer.

**Windows:** Download and run the Windows installer, follow the installation wizard, then launch CLion.

**macOS:** Check the processor in About This Mac from the Apple menu. Choose Apple Silicon for an M-series chip or Intel for an Intel processor. Open the downloaded disk image, drag CLion into Applications, and launch it from there.

## 3. Activate the student license in CLion

1. Select JetBrains Account login when the activation window appears on first launch.
2. Sign into the account that received the student license in Section 1. Complete the browser login and return to CLion.
3. Select the available student education license and activate it as instructed.
4. From the welcome screen, use Manage Licenses to reopen activation. With a project open, look under Help > Manage Subscriptions. Menu labels may differ between versions.

If no license is available, check the account, confirm application approval, and refresh the license list. Complete the application and association rather than repeatedly reinstalling the IDE.

## 4. Prepare the compiler

**Windows:** Use bundled MinGW. If prompted to select a toolchain, choose MinGW, then Bundled MinGW, and wait for compiler detection. If no prompt appears, search settings for Toolchains.

**macOS:** Open the system Terminal, run this command, and finish the Command Line Tools installation dialog. Wait for completion before returning to CLion. Skip installation if the tools are already installed.

```bash
xcode-select --install
```

CLion then uses the automatically detected Apple Clang compiler.

## 5. Create and run Hello World

1. Click New Project on the welcome screen.
2. Select C++ Executable and C++17, choose a local folder, and create the project.
3. Wait for the project to load. Open the generated main.cpp and replace its contents with:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World\n";
    return 0;
}
```

You can also copy the code from the accompanying hello.cpp.

Click the green run icon beside main, or select your project and click Run at the top right. The first run compiles the program; wait for it to finish.

When the Run window shows this line, local setup is complete:

```text
Hello World
```

This program requires no input.

References: [Student Pack application](https://www.jetbrains.com/academy/student-pack/), [CLion activation](https://www.jetbrains.com/help/clion/register.html), [Windows compiler setup](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html), [macOS developer tools](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-macos.html).
