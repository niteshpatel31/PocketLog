CREATE TABLE users(
    id UUID primary key,
    email TEXT UNIQUE NOT NULL,
    password_hash TEXT NOT NULL,
    name TEXT,
    created_at timestamp DEFAULT NOW(),
    updated_at timestamp DEFAULT NOW()
)