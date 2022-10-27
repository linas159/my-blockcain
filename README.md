# My Blockcain

Simple blockchain implementation for Vilnius University "Blockchain technologies" course.

## Usage

Download the code files and run them on Visual Studio.

## Blockchain executable commands:

### 1. Command "genUsers" - generates 1000 new users.
###

### 2. Command "printUsers" - prints all of the users' information in the terminal.
![image](https://user-images.githubusercontent.com/93277316/198257668-3437dad0-23bb-4254-b660-55738079a01d.png)
###

### 3. Command "printUser (number)" - prints specific user's information in the terminal.
![image](https://user-images.githubusercontent.com/93277316/198258469-6ad15d8f-f6de-4f2f-afa0-b06acb957e60.png)
###

### 4. Command "genTransactions" - generates 10000 new transactions.
###

### 5. Command "printTransactions" - prints all of the transactions' information in the terminal.
![image](https://user-images.githubusercontent.com/93277316/198259440-cfdc493b-e0e1-46ce-8715-cbeb399156c4.png)
###

### 6. Command "printTransaction (number)" - prints specific transaction's information in the terminal.
![image](https://user-images.githubusercontent.com/93277316/198259580-daaf93f2-0121-4914-a36b-32f0d9c07eea.png)
###

### 7. Command "startMining" - main program's command which generates blocks starts the mining process(expained blow).
![image](https://user-images.githubusercontent.com/93277316/198278677-b6fbd93d-75e4-4d64-9b95-9d9c75a26ee3.png)
###

### 8. Command "printBlock (number)" - used after command "startMining", prints specific block's information in the terminal.
![image](https://user-images.githubusercontent.com/93277316/198279142-5cddbc4d-b288-43ef-99a2-be463f3ef294.png)
###

### 9. Command "printAllBlocks" - used after command "startMining", prints all of the blocks' information in the terminal.
![image](https://user-images.githubusercontent.com/93277316/198279515-bf4595fd-87ed-4b1e-92ac-78a24bacc42c.png)
###

### 10. Command "quit" - stops the program.
###
##

## How it works

### Data generation

At startup, program generates 1000 users and 10000 transactions that are spread between users (they can be regenerated again).

### Block mining

When command is given program generates blocks which include 100 CORRECT (not malicious) transactions from the transaction pool. After each block generation the block is added to the blockchain.

### UI

When blocks are mined user can get information about each block.
