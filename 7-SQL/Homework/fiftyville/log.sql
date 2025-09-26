SELECT people.name, people.phone_number from people

JOIN bank_accounts ON people.id = bank_accounts.person_id


WHERE people.license_plate in (
    SELECT license_plate from bakery_security_logs
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 15
    AND minute < 24
)
AND bank_accounts.account_number in (
    SELECT account_number FROM atm_transactions
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND LOWER(atm_location) = 'leggett street'
    AND LOWER(transaction_type) = 'withdraw'
)
AND phone_number in(
    SELECT caller FROM phone_calls
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
)
AND passport_number in(
    SELECT passport_number FROM passengers
    WHERE flight_id = (
        SELECT flights.id FROM flights
        JOIN airports ON origin_airport_id = airports.id
        WHERE year = 2024
        AND month = 7
        AND day = 29
        AND LOWER(airports.city) = 'fiftyville'
        ORDER BY flights.hour, flights.minute
        LIMIT 1
        )
)

;

-- Cumplice

SELECT people.name, people.phone_number from people

JOIN bank_accounts ON people.id = bank_accounts.person_id


WHERE phone_number in(
    SELECT receiver FROM phone_calls
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller = '(367) 555-5533'
)

;


-- Cidade que escapou

SELECT airports.city from airports
JOIN flights ON airports.id = flights.destination_airport_id
JOIN passengers ON flights.id = passengers.flight_id
JOIN people ON passengers.passport_number = people.passport_number
JOIN bank_accounts ON people.id = bank_accounts.person_id

WHERE people.name = 'Bruce'
AND people.license_plate in (
    SELECT license_plate from bakery_security_logs
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 15
    AND minute < 24
)
AND bank_accounts.account_number in (
    SELECT account_number FROM atm_transactions
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND LOWER(atm_location) = 'leggett street'
    AND LOWER(transaction_type) = 'withdraw'
)
AND phone_number = '(367) 555-5533'

;
