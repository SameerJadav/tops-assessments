-- Create bank table
CREATE TABLE bank (
  branch_id INT PRIMARY KEY,
  branch_name VARCHAR(255),
  branch_city VARCHAR(255)
);
 

-- Create account_holder table
CREATE TABLE account_holder (
  account_holder_id INT PRIMARY KEY,
  account_no VARCHAR(255),
  account_holder_name VARCHAR(255),
  city VARCHAR(255),
  contact VARCHAR(20),
  date_of_account_created DATE,
  account_status VARCHAR(20),
  account_type VARCHAR(20),
  balance DECIMAL(10, 2)
);
 

 -- Create loan table
CREATE TABLE loan (
  loan_no INT PRIMARY KEY,
  branch_id INT,
  account_holder_id INT,
  loan_amount DECIMAL(10, 2),
  loan_type VARCHAR(255),
  FOREIGN KEY (branch_id) REFERENCES bank (branch_id),
  FOREIGN KEY (account_holder_id) REFERENCES account_holder (account_holder_id)
);


-- Insert sample data into bank table
INSERT INTO
 bank (branch_id, branch_name, branch_city)
VALUES
 (1, 'SBI Main Branch', 'Delhi'),
 (2, 'HDFC Nehru Place', 'Delhi'),
 (3, 'ICICI Bandra', 'Mumbai');


-- Insert sample data into account_holder table
INSERT INTO
 account_holder (
 account_holder_id,
 account_no,
 account_holder_name,
 city,
 contact,
 date_of_account_created,
 account_status,
 account_type,
 balance
 )
VALUES
 (
 101,
 'ACC101',
 'Amit Patel',
 'Delhi',
 '0123456789',
 '2023-01-10',
 'active',
 'savings',
 10000.00
 ),
 (
 102,
 'ACC102',
 'Priya Sharma',
 'Delhi',
 '0123456789',
 '2023-02-20',
 'active',
 'savings',
 5000.00
 ),
 (
 103,
 'ACC103',
 'Rahul Verma',
 'Mumbai',
 '0123456789',
 '2023-03-15',
 'active',
 'savings',
 15000.00
 );


-- Insert sample data into loan table
INSERT INTO
 loan (loan_no, branch_id, account_holder_id, loan_amount, loan_type)
VALUES
 (1, 1, 101, 50000.00, 'personal'),
 (2, 2, 102, 100000.00, 'home'),
 (3, 3, 103, 75000.00, 'business');


-- Intra bank transfer transaction
START TRANSACTION;


-- Account A (Amit Patel) transfers $100 to Account B (Priya Sharma)
UPDATE
 account_holder
SET
 balance = balance - 100
WHERE
 account_holder_id = 101;


UPDATE
 account_holder
SET
 balance = balance + 100
WHERE
 account_holder_id = 102;


COMMIT;


-- Fetch details of account holders from the same city
SELECT
 *
FROM
 account_holder
WHERE
 city IN (
 SELECT DISTINCT
 city
 FROM
 account_holder
 GROUP BY
 city
 HAVING
 COUNT(*) > 1
 );


-- Fetch account number and account holder name, whose accounts were created after the 15th of any month
SELECT
 account_no,
 account_holder_name
FROM
 account_holder
WHERE
 DAY(date_of_account_created) > 15;


-- Display the city name and count the branches in that city
SELECT
 branch_city,
 COUNT(*) AS Count_Branch
FROM
 bank
GROUP BY
 branch_city;


-- Display account holder’s id, account holder’s name, branch id, and loan amount for people who have taken loans
SELECT
 ah.account_holder_id,
 ah.account_holder_name,
 l.branch_id,
 l.loan_amount
FROM
 account_holder ah
 JOIN loan l ON ah.account_holder_id = l.account_holder_id;
