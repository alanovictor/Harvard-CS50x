  SELECT * FROM passengers
    JOIN flights ON passengers.flight_id = flights.id
    JOIN airports AS origin ON flights.origin_airport_id = origin.id
    JOIN airports AS destination ON flights.destination_airport_id = destination.id
    WHERE year = 2024
    AND month = 7
    AND day = 29
    AND LOWER(origin.city) = 'fiftyville'
;
