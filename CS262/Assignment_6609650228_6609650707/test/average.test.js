const avrg = require('../src/average');

//  Test cases for average function 
describe('average function', () => {
    test('should return correct average when all values are in range', () => {
        let result = avrg([10, 20, 30], 5, 50);
        expect(result.average).toBe(20);
        expect(result.total.valid).toBe(3);
    });

    test('should ignore values out of range', () => {
        let result = avrg([10, 200, 30], 5, 50);
        expect(result.average).toBe(20);
        expect(result.total.valid).toBe(2);
    });

    test('should return -999 when no valid values', () => {
        let result = avrg([200, 300, 400], 5, 50);
        expect(result.average).toBe(-999);
        expect(result.total.valid).toBe(0);
    });

    test('should return -999 when input is not an array', () => {
        let result = avrg("string", 5, 50);
        expect(result.average).toBe(-999);
        expect(result.total.valid).toBe(0);
    });

    test('should return -999 when input is an empty array', () => {
        let result = avrg([], 5, 50);
        expect(result.average).toBe(-999);
        expect(result.total.valid).toBe(0);
    });
});
