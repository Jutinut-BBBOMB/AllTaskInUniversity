// spec.js
// Jutinut Ratanamongkonkul 6609650228

describe('Consumption Calculator Test', function() {
    it('should calculate total caffeine and tar intake correctly', async function() {
        //Disable Angular wait BEFORE opening the page
        await browser.waitForAngularEnabled(false);

        // Open the web application
        await browser.get('https://www.globalsqa.com/angularJs-protractor/ConsumptionCalculator/');

        // Locate and fill the coffee input
        let coffeeInput = element.all(by.css("form input[name='quantity']")).get(0);
        await coffeeInput.clear();
        await coffeeInput.sendKeys('2');
        console.log("Entered 2 cups of coffee");

        // Set caffeine per cup to 95 mg
        let caffeinePerUnitInput = element.all(by.css("form input[name='perUnit']")).get(0);
        await caffeinePerUnitInput.clear();
        await caffeinePerUnitInput.sendKeys('95');
        console.log("Set caffeine per cup to 95 mg");

        // Locate and fill the cigarette input
        let cigaretteInput = element.all(by.css("form input[name='quantity']")).get(1);
        await cigaretteInput.clear();
        await cigaretteInput.sendKeys('4');
        console.log("Entered 4 cigarettes");

        // Set tar per cigarette to 20 mg
        let tarPerUnitInput = element.all(by.css("form input[name='perUnit']")).get(1);
        await tarPerUnitInput.clear();
        await tarPerUnitInput.sendKeys('20');
        console.log("Set tar per cigarette to 20 mg");

        // Calculate total intake
        let caffeinePerCup = 95; // mg
        let tarPerCigarette = 20; // mg
        let totalCaffeine = 2 * caffeinePerCup;
        let totalTar = 4 * tarPerCigarette;

        console.log("Total caffeine intake: " + totalCaffeine + " mg");
        console.log("Total tar intake: " + totalTar + " mg");

        // Verify input values
        expect(await coffeeInput.getAttribute('value')).toEqual('2');
        expect(await caffeinePerUnitInput.getAttribute('value')).toEqual('95');
        expect(await cigaretteInput.getAttribute('value')).toEqual('4');
        expect(await tarPerUnitInput.getAttribute('value')).toEqual('20');
        console.log("Inputs and per-unit values are correct");

        // Optional: Verify calculated totals showing on page
        let caffeineTotal = element.all(by.css("form input[name='total']")).get(0);
        let tarTotal = element.all(by.css("form input[name='total']")).get(1);
        expect(await caffeineTotal.getAttribute('value')).toBe(totalCaffeine.toString());
        expect(await tarTotal.getAttribute('value')).toBe(totalTar.toString());

        // Validate calculated values
        expect(totalCaffeine).toBe(190);
        expect(totalTar).toBe(80);
        console.log("Calculation results are correct");
    });
});
