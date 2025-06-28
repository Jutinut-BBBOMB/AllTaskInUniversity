// conf.js
///Jutinnut Ratanamongkonkul 6609650228

exports.config = {
    framework: 'jasmine',
    capabilities:{
        browserName: 'firefox'
    },
    //กำหนดให้ Selenium Server ทำ Action
    seleniumAddress: 'http://localhost:4444/wd/hub',
    //กำหนดให้เรียก webdriver บน browser ทำ Action
    //directConnect: true,
    specs:['spec.js'] //Name of the file containing test cases
    } ;