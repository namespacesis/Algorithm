SELECT 
    child.ITEM_ID,
    child.ITEM_NAME,
    child.RARITY
FROM ITEM_INFO AS parent
JOIN ITEM_TREE AS tree
    ON parent.ITEM_ID = tree.PARENT_ITEM_ID
JOIN ITEM_INFO AS child
    ON tree.ITEM_ID = child.ITEM_ID
WHERE parent.RARITY = 'RARE'
ORDER BY child.ITEM_ID DESC;
