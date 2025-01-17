# Ton-ton: Online Shop Market

Ton-ton is an online shop market developed using the **Qt framework**. It allows users to add, edit, and delete products.

## Prerequisites
Before initializing this program, ensure the following are installed on your system:
- **Qt Framework** (for GUI development)
- **PostgreSQL** and **pgAdmin** (for database management)

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Amirbekoni/Ton-ton.git

To initialize this program (You should have already installed Qt and PostgreSql):
## 1. git clone https://github.com/Amirbekoni/Ton-ton.git
## 2. Open pgAdmin and create a new database named "ShopMarket".
## 3. Create new tables in pgAdmin:
  CREATE TABLE users (
    name VARCHAR(128) NOT NULL,
    password VARCHAR(128) NOT NULL,
    email VARCHAR(128) NOT NULL
);

CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    user_name VARCHAR(255) NOT NULL,
    product_name VARCHAR(255) NOT NULL,
    price DOUBLE PRECISION NOT NULL,
    date DATE
);
## 4. Build and Run the Application:
Open the project in the Qt Creator IDE.
Configure the build settings.
Compile and run the application.
