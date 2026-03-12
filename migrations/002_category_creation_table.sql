CREATE TABLE categories(
    id UUID PRIMARY KEY,
    user_id UUID REFERENCES users(id),
    name TEXT,
    type TEXT
)