const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');

const app = express();

app.use(bodyParser.json());

// ���ӵ�MongoDB
mongoose.connect('mongodb://localhost/notebook', { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => console.log('MongoDB Connected'))
    .catch(err => console.log(err));

// ʹ��routes
app.use('/api/notes', require('./routes/notes'));

const port = process.env.PORT || 5000;

app.listen(port, () => console.log(`Server running on port ${port}`));


const mongoose = require('mongoose');

const NoteSchema = new mongoose.Schema({
    content: {
        type: String,
        required: true
    },
    date: {
        type: Date,
        default: Date.now
    }
});

module.exports = Note = mongoose.model('note', NoteSchema);


const express = require('express');
const router = express.Router();
const Note = require('../models/Note');

// ��ӱʼ�
router.post('/', async (req, res) => {
    const newNote = new Note({
        content: req.body.content
    });
    try {
        const note = await newNote.save();
        res.json(note);
    } catch (err) {
        res.json({ message: err });
    }
});

// ��ȡ���бʼ�
router.get('/', async (req, res) => {
    try {
        const notes = await Note.find();
        res.json(notes);
    } catch (err) {
        res.json({ message: err });
    }
});

// ɾ���ʼ�
router.delete('/:noteId', async (req, res) => {
    try {
        const removedNote = await Note.remove({ _id: req.params.noteId });
        res.json(removedNote);
    } catch (err) {
        res.json({ message: err });
    }
});

// ���±ʼ�
router.patch('/:noteId', async (req, res) => {
    try {
        const updatedNote = await Note.updateOne(
            { _id: req.params.noteId },
            { $set: { content: req.body.content } }
        );
        res.json(updatedNote);
    } catch (err) {
        res.json({ message: err });
    }
});

module.exports = router;


// server.js
const passport = require('passport');
const passportJWT = require('passport-jwt');

const ExtractJwt = passportJWT.ExtractJwt;
const JwtStrategy = passportJWT.Strategy;

const jwtOptions = {
    jwtFromRequest: ExtractJwt.fromAuthHeaderAsBearerToken(),
    secretOrKey: 'your_secret_key'
};

const strategy = new JwtStrategy(jwtOptions, (jwtPayload, done) => {
    User.findById(jwtPayload.id)
        .then(user => {
            return done(null, user);
        })
        .catch(err => {
            return done(err, false);
        });
});

passport.use(strategy);
app.use(passport.initialize());


// models/User.js
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');

const UserSchema = new mongoose.Schema({
    username: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true
    }
});

module.exports = User = mongoose.model('user', UserSchema);


// routes/auth.js
const express = require('express');
const router = express.Router();
const User = require('../models/User');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

// ע��
router.post('/register', async (req, res) => {
    const hashedPassword = await bcrypt.hash(req.body.password, 10);
    const newUser = new User({
        username: req.body.username,
        password: hashedPassword
    });
    try {
        const user = await newUser.save();
        res.json(user);
    } catch (err) {
        res.json({ message: err });
    }
});

// ��¼
router.post('/login', async (req, res) => {
    const user = await User.findOne({ username: req.body.username });
    if (!user) {
        return res.status(404).send('�û�������');
    }
    const isMatch = await bcrypt.compare(req.body.password, user.password);
    if (isMatch) {
        const token = jwt.sign({ id: user.id }, 'your_secret_key', { expiresIn: 3600 });
        res.json({ token });
    } else {
        res.status(401).send('�������');
    }
});

module.exports = router;


// routes/notes.js
const { check, validationResult } = require('express-validator');

// ��ӱʼ�
router.post('/', [
    check('content').not().isEmpty().withMessage('���ݲ���Ϊ��')
], async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
        return res.status(400).json({ errors: errors.array() });
    }
    // ...����ʼǵ��߼�
});


// server.js
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});


// server.js
const helmet = require('helmet');

app.use(helmet());
// JavaScript source code
