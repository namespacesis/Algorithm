SELECT D.ID
FROM ECOLI_DATA AS D
INNER JOIN (SELECT B.ID
            FROM ECOLI_DATA AS B
            INNER JOIN (SELECT ID
                       FROM ECOLI_DATA
                       WHERE PARENT_ID IS NULL
           ) AS A ON B.PARENT_ID = A.ID
           ) AS C ON D.PARENT_ID = C.ID
ORDER BY ID;
            
