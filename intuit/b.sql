SELECT
    a.username,
    CONCAT('.',SUBSTRING_INDEX(d.name, '.', -1),' ($',FORMAT(CAST(p.price AS DECIMAL(10,2)), 2),'/year) x ',COUNT(*)) AS tld,
    CONCAT('$',FORMAT(COUNT(*) * CAST(p.price AS DECIMAL(10,2)), 2)) AS total
FROM accounts a
JOIN domains d
    ON a.id = d.account_id
JOIN prices p
    ON p.tld = SUBSTRING_INDEX(d.name, '.', -1)
WHERE d.expiration_date LIKE '2022-08-%'
GROUP BY
    a.username,
    SUBSTRING_INDEX(d.name, '.', -1),
    CAST(p.price AS DECIMAL(10,2))
ORDER BY
    a.username ASC,
    COUNT(*) * CAST(p.price AS DECIMAL(10,2)) DESC,
    SUBSTRING_INDEX(d.name, '.', -1) ASC;