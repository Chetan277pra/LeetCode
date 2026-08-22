DELETE FROM Person as p
WHERE id != (
    SELECT min(id) from Person where 
    email = p.email
)
