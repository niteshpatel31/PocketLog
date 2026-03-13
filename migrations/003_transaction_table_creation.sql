CREATE TABLE transactions(
    id UUID PRIMARY KEY,
    user_id UUID REFERENCES users(id),
    category_id UUID REFERENCES categories(id),
    amount NUMERIC,
    note TEXT,
    description TEXT,
    asset BYTEA,
    created_at TIMESTAMP DEFAULT NOW()
)